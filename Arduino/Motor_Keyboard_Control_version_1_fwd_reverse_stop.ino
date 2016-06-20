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

// Declare L298N Dual H-Bridge Motor Controller directly since there is not a library to load.

int overallSpeed = 170;

// Motor 1
int dir1PinA = 2;
int dir2PinA = 3;
int speedPinA = 9; // Needs to be a PWM pin to be able to control motor speed

// Motor 2
int dir1PinB = 4;
int dir2PinB = 5;
int speedPinB = 10; // Needs to be a PWM1 pin to be able to control motor speed

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

}

void loop() {

// Initialize the Serial interface:

if (Serial.available() > 0) {
int inByte = Serial.read();
int speed; // Local variable

switch (inByte) {

//______________Motor 1______________

case 'a': // Motor 1 Forward
analogWrite(speedPinA, overallSpeed);//Sets speed variable via PWM 
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Forward"); // Prints out “Motor 1 Forward” on the serial monitor
Serial.println("   "); // Creates a blank line printed on the serial monitor
break;

case 'b': // Motor 1 Stop (Freespin)
analogWrite(speedPinA, 0);
digitalWrite(dir1PinA, LOW);
digitalWrite(dir2PinA, HIGH);
Serial.println("Motor 1 Stop");
Serial.println("   ");
break;

case 'c': // Motor 1 Reverse
analogWrite(speedPinA, overallSpeed);
digitalWrite(dir1PinA, HIGH);
digitalWrite(dir2PinA, LOW);
Serial.println("Motor 1 Reverse");
Serial.println("   ");
break;

//______________Motor 2______________

case 'd': // Motor 2 Forward
analogWrite(speedPinB, overallSpeed);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Forward");
Serial.println("   ");
break;

case 'e': // Motor 1 Stop (Freespin)
analogWrite(speedPinB, 0);
digitalWrite(dir1PinB, LOW);
digitalWrite(dir2PinB, HIGH);
Serial.println("Motor 2 Stop");
Serial.println("   ");
break;

case 'f': // Motor 2 Reverse
analogWrite(speedPinB, overallSpeed);
digitalWrite(dir1PinB, HIGH);
digitalWrite(dir2PinB, LOW);
Serial.println("Motor 2 Reverse");
Serial.println("   ");
break;

default:
// turn all the connections off if an unmapped key is pressed:
for (int thisPin = 2; thisPin < 11; thisPin++) {
digitalWrite(thisPin, LOW);
}
  }
    }
      }
