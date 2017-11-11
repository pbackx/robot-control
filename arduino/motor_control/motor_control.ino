#include <SoftwareSerial.h>

int incoming = 0;
int leftMotor = 0;
int rightMotor = 0;

int PIN_ENABLEA_RIGHT = 10;
int PIN_IN1_RIGHT = 9;
int PIN_IN2_RIGHT = 8;

int PIN_ENABLEB_LEFT = 5;
int PIN_IN3_LEFT = 7;
int PIN_IN4_LEFT = 6;

// int PIN_LEFT_CONTROL = 11;
// int PIN_RIGHT_CONTROL = 12;

int STOP = 0;
int FORWARD = 1;
int BACKWARD = -1;

SoftwareSerial BT(2, 3); // RX | TX

void setup() {
//  pinMode(PIN_LEFT_CONTROL, INPUT);
//  pinMode(PIN_RIGHT_CONTROL, INPUT);

  pinMode(PIN_ENABLEA_RIGHT, OUTPUT);
  pinMode(PIN_IN1_RIGHT, OUTPUT);
  pinMode(PIN_IN2_RIGHT, OUTPUT);
  pinMode(PIN_ENABLEB_LEFT, OUTPUT);
  pinMode(PIN_IN3_LEFT, OUTPUT);
  pinMode(PIN_IN4_LEFT, OUTPUT);

  Serial.begin(9600);
  BT.begin(38400);
}

void loop() {
  // listen for a response from the HC-05 and write it to the serial monitor
  if (BT.available()) {
    incoming = BT.read();
    Serial.write(incoming);
    switch(incoming) {
      case 'L':
        leftMotor = FORWARD;
        break;
      case 'l':
        leftMotor = STOP;
        break;
      case 'o':
        leftMotor = BACKWARD;
        break;
      case 'R':
        rightMotor = FORWARD;
        break;
      case 'r':
        rightMotor = STOP;
        break;
      case 'f':
        rightMotor = BACKWARD; 
    }
  }

  // listen for user input and send it to the HC-05
//  if (Serial.available())
//    BT.write(Serial.read());

  
//  leftMotor = digitalRead(PIN_LEFT_CONTROL);
//  rightMotor = digitalRead(PIN_RIGHT_CONTROL);

  if (leftMotor == FORWARD) {
    analogWrite(PIN_ENABLEB_LEFT, 100);
    digitalWrite(PIN_IN3_LEFT, LOW);
    digitalWrite(PIN_IN4_LEFT, HIGH);    
  } else if (leftMotor == BACKWARD) {
    analogWrite(PIN_ENABLEB_LEFT, 100);
    digitalWrite(PIN_IN3_LEFT, HIGH);
    digitalWrite(PIN_IN4_LEFT, LOW);    
  } else {
    digitalWrite(PIN_IN3_LEFT, LOW);
    digitalWrite(PIN_IN4_LEFT, LOW);
  }

  if (rightMotor == FORWARD) {
    analogWrite(PIN_ENABLEA_RIGHT, 100);
    digitalWrite(PIN_IN1_RIGHT, LOW);
    digitalWrite(PIN_IN2_RIGHT, HIGH);    
  } else if (rightMotor == BACKWARD) {
    analogWrite(PIN_ENABLEA_RIGHT, 100);
    digitalWrite(PIN_IN1_RIGHT, HIGH);
    digitalWrite(PIN_IN2_RIGHT, LOW);    
  } else {
    digitalWrite(PIN_IN1_RIGHT, LOW);
    digitalWrite(PIN_IN2_RIGHT, LOW);
  }
}
