//6/16/16
//Move two motors (or 4 connected in parallel) using keyboard
//Use with L298N Dual H-Bridge Motor Controller

//Keyboard Controls:
//
// 'a' -Motor 1 Forward
// 'b' -Motor 1 Stop
// 'c' -Motor 1 Reverse
//
// 'd' -Motor 2 Forward
// 'e' -Motor 2 Stop
// 'f' -Motor 2 Reverse

//'g' -Increase speed
//'h' -Decrease speed

//'8' -Open Hatch
//'9' -Close Hatch

//'i' -Both Motors Forward
//'k' -Both Motors Reverse
//'j' -Turn Left
//'k' -Turn Right
//'space bar' -Both Motors Stop

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

int overallSpeed = 130;

// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 6; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 11; // Needs to be a PWM1 pin to be able to control motor speed

String direction1; //direction of motor 1
String direction2; //direction of motor 2




//Box and Hatch
#include <Servo.h>

Servo latchservo;
Servo doorservo;


void setup() {  // Setup runs once per reset
// initialize serial communication @ 9600 baud:
Serial.begin(9600);

//Define L298N Dual H-Bridge Motor Controller Pins

pinMode(dir1PinA,OUTPUT);
pinMode(dir2PinA,OUTPUT);
pinMode(speedPinA,OUTPUT);
pinMode(dir1PinB,OUTPUT);
pinMode(dir2PinB,OUTPUT);
pinMode(speedPinB,OUTPUT);

//Box and Hatch
//latchservo.attach(9); 
//latchservo.write(0);
//delay(1000);
//latchservo.detach();
while (! Serial); // wait until serial is available
Serial.println("Enter 8 to open the hatch. Enter 9 to close the hatch");

}



void loop() {

// Initialize the Serial interface:

if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Local variable

switch (inByte) {

//______________Motor 1______________

case 'a': // Motor 1 Forward
forward(1);

Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;

case 'b': // Motor 1 Stop (Freespin)
stopmotor(1);
Serial.println("Motor 1 Stop");
Serial.println("   ");
break;

case 'c': // Motor 1 Reverse
reverse(1);
Serial.println("Motor 1 Reverse");
Serial.println("   ");
break;

//______________Motor 2______________

case 'd': // Motor 2 Forward
forward(2);

Serial.println("Motor 2 Forward");
Serial.println("   ");
break;

case 'e': // Motor 2 Stop (Freespin)
stopmotor(2);
Serial.println("Motor 2 Stop");
Serial.println("   ");
break;

case 'f': // Motor 2 Reverse
reverse(2);

Serial.println("Motor 2 Reverse");
Serial.println("   ");
break;

// Change Overall Speed
case 'g': // Increase the speed
  overallSpeed += 10;
  Serial.println(direction1);
  // Allow motors to continue their direction with new overall speed
  if(direction1 == "forward"){
    forward(1);
    Serial.println("I'm working");
  }
  else if(direction1 == "reverse"){
    reverse(1);
  }
  else if(direction1 == "stop"){
    stopmotor(1);
  }
  
  if(direction2 == "forward"){
    forward(2);
  }
  else if(direction2 == "reverse"){
    reverse(2);
  }
  else if(direction2 == "stop"){
    stopmotor(2);
  }
  
  Serial.println(overallSpeed);
break;


case 'h': // Decrease the speed
  overallSpeed -= 10;
  
  // Allow motors to continue their direction with new overall speed
  if(direction1 == "forward"){
    forward(1);
  }
  else if(direction1 == "reverse"){
    reverse(1);
  }
   else if(direction1 == "stop"){
    stopmotor(1);
  }
  if(direction2 == "forward"){
    forward(2);
  }
  else if(direction2 == "reverse"){
    reverse(2);
  }
  else if(direction1 == "stop"){
    stopmotor(2);
  }
  Serial.println(overallSpeed);
break;

case 'i': // Both Motors Forward
forward(1);
forward(2);
Serial.println("Both Motors Forward"); 
Serial.println("   "); 
break;

case 'k': // Both Motors Reverse
reverse(1);
reverse(2);
Serial.println("Both Motors Reverse"); 
Serial.println("   "); 
break;

case 'j': //Turn Left
forward(1);
reverse(2);
Serial.println("Turn Left"); 
Serial.println("   "); 
break;

case 'l':  //Turn Right
reverse(1);
forward(2);
Serial.println("Turn Right"); 
Serial.println("   "); 
break;

case ' ':  //Both Motors Stop
stopmotor(1);
stopmotor(2);
Serial.println("Both Motors Stop"); 
Serial.println("   "); 
break;


//Box and Hatch
case '8': //latch servo
  latchservo.attach(9);
  latchservo.write(90);
  delay(2500);
  latchservo.detach();
  doorservo.attach(10);
  doorservo.write(0);
  delay(1200);
  doorservo.detach();
  
break;

case '9': //continuous servo
  doorservo.attach(10);
  doorservo.write(180);
  delay(1200);
  doorservo.detach();
  latchservo.attach(9);
  latchservo.write(0);
  delay(2500);
  latchservo.detach();
break;

default:
// turn all the connections off if an unmapped key is pressed:
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
  }
    }
      }

//Define Functions



void forward(int motor) {
  if (motor == 1){
    analogWrite(speedPinA, overallSpeed); //Sets speed variable via PWM 
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    direction1 = "forward";  // Apostrophes used because char is not constant
  }
  else
  {
    analogWrite(speedPinB, overallSpeed); //Sets speed variable via PWM 
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    direction2 = "forward";
  }
}

void reverse(int motor) {
  if (motor == 1){
    analogWrite(speedPinA, overallSpeed); //Sets speed variable via PWM 
    digitalWrite(dir1PinA, HIGH);
    digitalWrite(dir2PinA, LOW);
    direction1 = "reverse";  // Apostrophes used because char is not constant
  }
  else
  {
    analogWrite(speedPinB, overallSpeed); //Sets speed variable via PWM 
    digitalWrite(dir1PinB, HIGH);
    digitalWrite(dir2PinB, LOW);
    direction2 = "reverse";
  }
}

void stopmotor(int motor) {
  if (motor ==1){
    analogWrite(speedPinA, 0);
    digitalWrite(dir1PinA, LOW);
    digitalWrite(dir2PinA, HIGH);
    direction1 = "stop";
  }
  else
  {
    analogWrite(speedPinB, 0);
    digitalWrite(dir1PinB, LOW);
    digitalWrite(dir2PinB, HIGH);
    direction2 = "stop";
  }
}

