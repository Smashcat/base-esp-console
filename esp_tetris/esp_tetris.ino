#include "defs.h"
extern "C"
{
  #include "user_interface.h"
}

#include "pitches.h"
#include <EEPROM.h>
#if NEW_NETWORK
#include "WebSocketClient.h"
#include "ESP8266WiFi.h"

WebSocketClient webSocket(false);

#else
#include <WebSocketsClient.h>
#include <ESP8266WiFi.h>
WebSocketsClient webSocket;
#endif

#include "SPI.h"
#include "TFT_eSPI.h"
#include <Ticker.h>
#include "music.h"
#include "vars.h"
#include "gfx.h"
#include "headers.h"

TFT_eSPI tft = TFT_eSPI();
TFT_eSprite img = TFT_eSprite(&tft);
TFT_eSprite sprite1 = TFT_eSprite(&tft);
TFT_eSprite sprite2 = TFT_eSprite(&tft);
TFT_eSprite spriteTmp = TFT_eSprite(&tft);

#include "keyboard.h"
#include "menus.h"
#include "stars.h"
#if NEW_NETWORK
#include "networknew.h"
#else
#include "network.h"
#endif
#include "funcs.h"
#include "gameFuncs.h"
#include "screens.h"


void setup() {

  // Hack to allow LCD to reset and be ready before ESP is active
  pinMode(TFT_RST,OUTPUT);
  digitalWrite(TFT_RST, LOW);
  delay(25);
  digitalWrite(TFT_RST, HIGH);
  delay(100);

  setSong(0);
  za = random(256);
  zb = random(256);
  zc = random(256);
  zx = random(256);
#if USE_SERIAL
  Serial.begin(115200);
  Serial.println("\n\nOK");
#else
  pinMode(BUT_RLEFT,INPUT_PULLUP);
  pinMode(BUT_RRIGHT,INPUT_PULLUP);
#endif
  makeColors();
  tft.init();
  tft.fillScreen(0);

  system_timer_reinit();
  os_timer_setfn(&timer, timerCallback, NULL);
  os_timer_arm(&timer, 10, true); // 50FPS

  //networkStatus=NETWORK_CONNECTING; //NETWORK_OFFLINE;
  networkStatus=NETWORK_OFFLINE;
  loadConfig();
  
#if USE_SERIAL
  Serial.print("Name = ");
  Serial.println(myName);
  Serial.print("SSID = ");
  Serial.println(wifiName);
  Serial.print("Pass = ");
  Serial.println(wifiPassword);
#endif
  setState(STATE_INTRO);
//  is2Player=true;
//  setState(STATE_PLAYING);
}

void loop() {
  checkWebSocket();
  checkButtons();
  if(state!=STATE_PLAYING){
    updateStars();
  }
  // Check connection status every second
  if(connectCheckTmr>=CONNECT_CHECK_INTERVAL){
    resetConnectCheckTmr();
    checkConnection();
  }
  if(state!=STATE_PLAYING){
    showNetworkStatus();
  }
  switch(state){
    
    case STATE_INTRO:
      showIntro();
      break;
      
    case STATE_TITLE_SCREEN:
      showTitleScreen();
      break;

    case STATE_PLAYING:
      showStatePlaying();
      break;

    case STATE_CHOOSE_OPPONENT:
      chooseOpponent();
      break;

    case STATE_HIGH_SCORES:
      showHighScores();
      break;
 
    case STATE_SETTINGS:
      showSettings();
      break;

    case STATE_HELP:
      showHelp();
      break;

    case STATE_SETUP_NAME:
      showSetupName();
      break;
    
    case STATE_SETUP_WIFI:
      showSetupWiFi();
      break;

    case STATE_SETUP_ABOUT:
      showSetupAbout();
      break;

    case STATE_CHALLENGED:
      showChallenged();
      break;
      
    default:
      break;
  }
  delay(1);
  yield();
}
