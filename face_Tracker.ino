#include <Servo.h>

Servo pan_Servo;
Servo tilt_Servo;

int pan_Servo_Pin = 9;
int tilt_Servo_Pin = 10;

int x = 0;
int y  =0;
int ser_Char = 0;
int tilt_Channel = 1;
int pan_Channel = 0;

void setup() {
  pan_Servo.attach(pan_Servo_Pin);
  tilt_Servo.attach(tilt_Servo_Pin);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() <= 0);  // Wait for character on the serial port
  ser_Char = Serial.read();        // Copy the character from serial into the variable
  if(ser_Char == tilt_Channel) {    // Check to see if the tilt Servo must be moved
    while(Serial.available() <= 0);  // Wait for second command byte
    Serial.print("Move tilt servo: ");
    x = Serial.read();               //Read the angle from serial
    Serial.println(x);
    tilt_Servo.write(x);
  }
  else if(ser_Char == pan_Channel) {
    while(Serial.available() <= 0);  // Wait for second command byte
    Serial.print("Move pan servo: ");
    y = Serial.read();               //Read the angle from serial
    Serial.println(y);
    pan_Servo.write(y);
  }
}
