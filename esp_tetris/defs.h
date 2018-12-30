// true if using the dev version of the console - button mappings are different
#define DEV_VERSION       false

// True if using dev server for networking comms (addresses below)
#define DEV_SERVER        false

// True if serial port should output debugging data. Cannot be used in conjunction with A+B buttons
#define USE_SERIAL        false

// Leave following set to false - code is not finished!
#define NEW_NETWORK       false

// Number of starts in background of out-of-game screens
#define NSTARS            512


// There should be no need to alter anything below this line!

// Ping server once a minute
#define PING_INTERVAL     6000

#define TMP_STR_LEN       500

#if DEV_SERVER
#define GAME_SERVER_URL   "192.168.0.249"
#else
#define GAME_SERVER_URL   "www.smashcat.org"
#endif

#define GAME_SERVER_PORT  8888
#define MAX_OPPONENTS     30
#define APP_SIG0          101
#define APP_SIG1          102

#define BUT_UP     0
#define BUT_RLEFT  1
#define BUT_DOWN   2
#define BUT_RRIGHT 3
#if(DEV_VERSION)
#define BUT_LEFT 4
#else
#define BUT_LEFT  12
#endif
#define TFT_RST    4
#define DC         5
#define MISO      12
#define MOSI      13
#define SCLK      14
#define BUT_RIGHT 15
#define BUZZER    16

// program states
#define STATE_INTRO         0
#define STATE_TITLE_SCREEN  1
#define STATE_HIGH_SCORES   2
#define STATE_SETTINGS      3
#define STATE_HELP          4
#define STATE_SETUP_NAME    5
#define STATE_SETUP_WIFI    6
#define STATE_SETUP_ABOUT   7

// In game
#define STATE_CHALLENGED      70
#define STATE_PICK_PLAYER     80
#define STATE_GAME_START      90
#define STATE_PLAYING         100
#define STATE_CHOOSE_OPPONENT 110
#define STATE_GAME_END        120

#define RED_TO_YELLOW   0
#define GREEN_TO_BLUE   1
#define PURPLE_TO_WHITE 2
#define WHITE_TO_BLUE   3
#define RED_TO_BLUE     4
#define BLACK_TO_RED    5
#define BLACK_TO_BLACK  6

#define KS_IDLE         0
#define KS_OPENING      1
#define KS_EDITING      2
#define KS_CLOSING      3

// Actually 7 displayed shapes, but first is blank - makes some other logic easier :)
#define TOTAL_SHAPES      8
#define TOTAL_ROTATIONS   4
#define TOTAL_COORDINATES 4

#define KEYBOARD_ACTIVE 0
#define KEYBOARD_CLOSED 1
#define KEYBOARD_SAVED  2

#define GRID_X            16
#define GRID_Y            33
#define GRID_HEIGHT       23
#define GRID_WIDTH        10
#define FIRST_VISIBLE_ROW 3

// Speed of game at start (interval in 1/20 seconds between successive downward movements of player's block)
#define GAME_SPEED_START  30
// Maximum speed of game (as above)
#define GAME_SPEED_END    1
#define REPEAT_SPEED_RESET    20;
#define REPEAT_SPEED_REPEAT   2;


#define MY_NAME_IX      3
#define MY_NAME_LEN     17

#define WIFI_SSID_IX    20
#define WIFI_SSID_LEN   65

#define WIFI_PASS_IX    85
#define WIFI_PASS_LEN   65

#define SOUND_TYPE_IX   151

#define NETWORK_OFF         0
#define NETWORK_CONNECTING  1
#define NETWORK_CONNECTED   2
#define NETWORK_OFFLINE     3
#define NETWORK_UNDEFINED   4
#define WIFI_LOGO_DISPLAY_TIME  500
// 20 = 1 second
#define CONNECT_CHECK_INTERVAL  100
#define CURSOR_BLINK_SPEED      80

#define COLOR_GREY  0x421
#define COLOR_RED   0x78
#define COLOR_GREEN 0xE003
#define COLOR_BLUE  0x0F00

#define GAMESTATE_DROPPING  0
#define GAMESTATE_DROPPED   1
#define GAMESTATE_FAST_DROP 2
#define GAMESTATE_CLEARING  3
#define GAMESTATE_GAME_OVER 4
#define GAMESTATE_WE_WIN    5
#define GAMESTATE_WE_LOSE   6

#define RESPONSE_NONE       0
#define RESPONSE_ACCEPT     1
#define RESPONSE_REJECT     2
#define RESPONSE_BUSY       3

#define SOUND_NONE          0
#define SOUND_EFFECTS       1
#define SOUND_ALL           2
