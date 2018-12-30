int16_t songTmr=0;
int16_t songFreq=0;
int16_t songPos=0;
int8_t songIX=-1;

int16_t effectTmr=0;
int16_t effectFreq=0;
int16_t effectPos=0;
int8_t effectIX=-1;

int16_t tetrisNotes[] = {
  // part 1
  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, 
  NOTE_C5, NOTE_B4, NOTE_A4, NOTE_R, NOTE_A4, 
  NOTE_C5, NOTE_E5, NOTE_D5, NOTE_C5, 
  NOTE_B4, NOTE_B4, NOTE_C5, NOTE_D5, 
  NOTE_E5, NOTE_C5, NOTE_A4, NOTE_R, NOTE_A4, 
  NOTE_R,
  
  NOTE_D5, NOTE_R, NOTE_D5, NOTE_F5, NOTE_A5, NOTE_G5, 
  NOTE_F5, NOTE_E5, NOTE_C5, NOTE_E5, 
  NOTE_D5, NOTE_C5, NOTE_B4, NOTE_R, NOTE_B4, 
  NOTE_C5, NOTE_D5, NOTE_E5, NOTE_C5, 
  NOTE_A4, NOTE_R, NOTE_A4, NOTE_R,

  // part 2
  NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3, 
  NOTE_C4, NOTE_A3, NOTE_GS3, NOTE_B3,
  NOTE_E4, NOTE_C4, NOTE_D4, NOTE_B3, 
  NOTE_C4, NOTE_E4, NOTE_A4, NOTE_R, NOTE_A4, 
  NOTE_GS4, NOTE_R

};

int8_t tetrisTimes[] = {
  

  // part 10
  10, 5, 5, 10, 
  5, 5, 9, 1, 5, 
  5, 10, 5, 5, 
  10, 5, 4, 10, 
  10, 10, 9, 1, 10, 
  10,
  
  9, 1, 5, 5, 10, 5, 
  5, 15, 5, 10, 
  5, 5, 9, 1, 5, 
  5, 10, 10, 10, 
  9, 1, 10, 10,

  // part 2
  20, 20, 20, 20, 
  20, 20, 20, 20,
  20, 20, 20, 20, 
  10, 10, 9, 1, 10, 
  30, 10
  
};

int16_t buttonNotes[] = {
  NOTE_C6,NOTE_C7,
};

int8_t buttonTimes[]={
  2,1,
};

int16_t blockLandNotes[]={NOTE_C5,NOTE_C4,NOTE_C3};
int8_t blockLandTimes[]={3,2,4};

int16_t tetris1Notes[]={NOTE_C5,NOTE_C6,NOTE_C5,NOTE_C6,};
int8_t tetris1Times[]={2,3,2,3,};

int16_t tetris2Notes[]={NOTE_C5,NOTE_G5,NOTE_C6,NOTE_C5,NOTE_G5,NOTE_C6,};
int8_t tetris2Times[]={2,2,3,2,2,3,};

int16_t tetris3Notes[]={NOTE_C5,NOTE_F5,NOTE_G5,NOTE_C6,NOTE_C5,NOTE_F5,NOTE_G5,NOTE_C6,};
int8_t tetris3Times[]={2,3,2,3,2,3,2,3,};

int16_t tetris4Notes[]={NOTE_C5,NOTE_F5,NOTE_G5,NOTE_C5,NOTE_C6,NOTE_C5,NOTE_F5,NOTE_G5,NOTE_C5,NOTE_C6,};
int8_t tetris4Times[]={2,3,2,3,3,2,3,2,3,3,};

int16_t gameOverNotes[]={NOTE_G4,NOTE_D4,NOTE_B3,NOTE_A3,NOTE_G3,NOTE_G4};
int8_t gameOverTimes[]={5,10,10,5,5,20};

struct tune {
  int16_t * notes;
  int8_t *  times;
  int16_t   length;
};

int16_t merryXmasNotes[] = {
  NOTE_B3, 
  NOTE_F4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4,
  NOTE_D4, NOTE_D4, NOTE_D4,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_G4, NOTE_F4,
  NOTE_E4, NOTE_E4, NOTE_E4,
  NOTE_A4, NOTE_A4, NOTE_B4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_D4, NOTE_B3, NOTE_B3,
  NOTE_D4, NOTE_G4, NOTE_E4,
  NOTE_F4
};

int8_t merryXmasTimes[] = {
  10,
  10, 5, 5, 5, 5,
  10, 10, 10,
  10, 5, 5, 5, 5,
  10, 10, 10,
  10, 5, 5, 5, 5,
  10, 10, 5, 5,
  10, 10, 10,
  20
};

int16_t countDownNotes[] = {
  NOTE_C5,NOTE_C6,NOTE_C5,
};

int8_t countDownTimes[]={
  2,1,1,
};

struct tune song[]={
  {tetrisNotes,tetrisTimes,65},       // 0 Main tune
  {buttonNotes,buttonTimes,3},        // 1 button noise
  {blockLandNotes,blockLandTimes,4},  // 2 block landing
  {tetris1Notes,tetris1Times,5},      // 3 clear 1 line
  {tetris2Notes,tetris2Times,7},      // 4 clear 2 lines
  {tetris3Notes,tetris3Times,9},      // 5 clear 3 lines
  {tetris4Notes,tetris4Times,11},     // 6 clear 4 lines
  {gameOverNotes,gameOverTimes,7},    // 7 game over
  {merryXmasNotes,merryXmasTimes,31}, // 8 merry xmas!
  {countDownNotes,countDownTimes,4},  // 9 count down bleeps
};

void setSong(int8_t s){
  songIX=s;
  songTmr=0;
  songFreq=0;
  songPos=0;
  if(s==-1){
    pinMode(BUZZER,INPUT);
    digitalWrite(BUZZER,0);
  }
}

void playEffect(int8_t s){
  effectIX=s;
  effectTmr=0;
  effectFreq=0;
  effectPos=0;
}
