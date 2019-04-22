#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include<String.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// our servo # counter
uint8_t servonum = 8;
long pulse;
uint16_t waittime = 300; 

int frd=1;
int fld=2;
int bld=3;
int brd=4;
int fru=5;
int flu=6;
int blu=7;
int bru=8;

// fru ke luar atas positif
// bru ke luar atas negatif
// blu ke luar atas positif
// flu ke luar atas negatif

int std_bld=-25;
int std_brd=-25;
int std_frd=-35;
int std_fld=10;

int std_flu=-10;
int std_fru=-2;
int std_blu=10;
int std_bru=-8;

int curr_bld, curr_blu, curr_fld ,curr_frd, curr_brd, curr_bru, curr_flu, curr_fru;
//
long DegreeToPulse(long x){
  pulse = (x*5/2) + 375;
  return pulse;
}

void MoveServo(uint8_t servonum, long x ){
  pwm.setPWM(servonum, 0, DegreeToPulse(x));
}

void awal(){
  MoveServo(brd, std_brd);
  delay(100);
  MoveServo(bru, std_bru);
  delay(100);
  MoveServo(frd, std_frd);
  delay(100);
  MoveServo(bld, std_bld);
  delay(100);
  MoveServo(blu, std_blu);
  delay(100);
  MoveServo(fld, std_fld);
  delay(100);
  MoveServo(flu, std_flu);
  delay(100);
  MoveServo(fru, std_fru);
  delay(100);
  
  curr_brd = std_brd;
  curr_bld = std_bld;
  curr_frd = std_frd;
  curr_fld = std_fld;
  curr_bru = std_bru;
  curr_blu = std_blu;
  curr_fru = std_fru;
  curr_flu = std_fld;
}


// x menandakan komponen servo mana
void fld_putar( String arah, int delta){
 
  Serial.println(arah);
  if (arah=="ccw")
  {
      Serial.println("ccw!");
      curr_fld = delta + curr_fld ;    
      MoveServo( fld , curr_fld );
    }
  if (arah=="cw")
  {
      Serial.println("cw!");
      curr_fld = curr_fld - delta ; 
      MoveServo( fld , curr_fld );
    }   
}

void frd_putar( String arah, int delta){
 
  Serial.println(arah);
  if (arah=="ccw")
  {
      Serial.println("ccw!");
      curr_frd = delta + curr_frd ;    
      MoveServo( frd , curr_frd );
    }
  if (arah=="cw")
  {
      Serial.println("cw!");
      curr_frd = curr_frd - delta ; 
      MoveServo( frd , curr_frd );
    }   
}

void brd_putar( String arah, int delta){
 
  Serial.println(arah);
  if (arah=="ccw")
  {
      Serial.println("ccw!");
      curr_brd = delta + curr_brd ;    
      MoveServo( brd , curr_brd );
    }
  if (arah=="cw")
  {
      Serial.println("cw!");
      curr_brd = curr_brd - delta ; 
      MoveServo( brd , curr_brd );
    }   
}


void bld_putar( String arah, int delta){
 
  Serial.println(arah);
  if (arah=="ccw")
  {
      Serial.println("ccw!");
      curr_bld = delta + curr_bld ;    
      MoveServo( bld , curr_bld );
    }
  if (arah=="cw")
  {
      Serial.println("cw!");
      curr_bld = curr_bld - delta ; 
      MoveServo( bld , curr_bld );
    }   
}


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("STARTING!"); 
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
  delay(10);
}

void loop() {  
  Serial.println("STATIS");
  awal();
  delay(2000);
  
  frd_putar("ccw",70);
  delay(1000);
  awal(); 
  fld_putar("cw",70);
  delay(1000);
  awal(); 
  fld_putar("cw",70);
  delay(1000);
  awal(); 
  fld_putar("cw",70);
  delay(1000);
}
