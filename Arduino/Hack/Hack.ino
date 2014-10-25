//MuddHacks Project
//Auto-Unlock Door
//Team Members: Nathan Miller, Eric Mueller, Rohan Nagpal, Vai Viswanathan

// 100 is unlocked
//  is locked

#include <Servo.h>
#define SERVOPIN 10
#define RASPI 13 //defines the digital port the raspberry pi uses
#define RPLUS 7 //defines the positive motor pole
#define RMINUS 12 //negative motor pole
#define REN 11 //motor enabling

int powerLevel = 225; //sets motor power level to 225
int lockTime = 250; //time to turn lock
boolean locked = true; //whether the door is locked or not
int piRead;
Servo servo;
int lockNum = 115;
int unlockNum = 25;


void setup(){
  Serial.begin(9600); // begins 9600 port
  pinMode(RASPI, INPUT); // sets RASPI as input
  pinMode(RPLUS, OUTPUT); //sets RPLUS as output
  pinMode(RMINUS, OUTPUT); //sets RPLUS as output
}

void loop()
{
  
}

void handleInput(){
  if (Serial.available()){
    piRead = Serial.read(); 
    if(piRead == 0){
      unlock();
    }
    if(piRead == 1){
      lock();
    }
    if(piRead == 2){
      returnState();
    }
  }
  
}

void initServo(){
  pinMode(SERVOPIN, OUTPUT);
  servo.attach(SERVOPIN);
}

void turnServo(int deg){
  initServo();
  servo.write(deg);
}

void returnState(){
  Serial.println(locked);
}

void unlock(){ //unlocks door
  if(locked){ //checks to see if the door is locked
    right();
    delay(lockTime);
    halt();
    locked = false;
    Serial.println("unlocked"); //resets the lock variable
  }
  else{
    Serial.println("error"); //returns error if already unlocked
  }
}

void lock(){      
  if(locked == false){ //checks to see if door is unlocked
    left();
    delay(lockTime);  //locktime will be in MS, want to change so we can pass integer seconds?
    halt();
    locked = true;
    Serial.println("locked"); //resets lock variable
  }
  else{
    Serial.println("error"); //returns error if already locked
  }
}

void right() //turns motor right
{
  turnServo(unlockNum);
}

void left() //turns motor left
{
  turnServo(lockNum);
}

