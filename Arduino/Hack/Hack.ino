//MuddHacks Project
//Auto-Unlock Door
//Team Members: Nathan Miller, Eric Mueller, Rohan Nagpal, Vai Viswanathan

// 0 is the command for unlocked
// 1 is command for locked
//2 is command for getState


#include <Servo.h>
#define SERVOPIN 10


boolean locked = true; //whether the door is locked or not
int piRead; //stores the input from raspberry pi
Servo servo; 
int lockNum = 115; //servo value to lock door
int unlockNum = 25; //servo value to unlock door


void setup(){
  Serial.begin(9600); // begins 9600 baud
}

void loop()
{
  handleInput();
}

void handleInput(){ //handles input from raspberry pi
  if (Serial.available()){ //checks to see if there is a reading from the pi
    piRead = Serial.read() - '0'; 
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

void initServo(){ //initializes servo
  pinMode(SERVOPIN, OUTPUT);
  servo.attach(SERVOPIN);
}

void turnServo(int deg){ //rotates servo to designated degrees
  initServo();
  servo.write(deg);
}

void returnState(){ //returns the locked/unlocked state of door
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

