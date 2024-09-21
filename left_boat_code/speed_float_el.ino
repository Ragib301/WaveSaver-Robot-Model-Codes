#include "BluetoothSerial.h"
#include <ESP32Servo.h>

Servo yaw; 


BluetoothSerial SerialBT;
char receivedChar;


#define left_motor_forward 12
#define left_motor_backward 13
#define right_motor_forward 16
#define right_motor_backward 17
#define left_motor_speed 14
#define right_motor_speed 4
#define spl 25
#define spr 25
#define led 2


const int freq = 5000;
const int resolution = 8;
const int ledChannel_y = 10;
const int ledChannel_x = 11;


void setup() {
  
  Serial.begin(115200);
  SerialBT.begin("left");


  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);


  ledcSetup(ledChannel_y, freq, resolution);
  ledcSetup(ledChannel_x, freq, resolution);
  
  ledcAttachPin(left_motor_speed, ledChannel_y);
  ledcAttachPin(right_motor_speed,ledChannel_x);

  
 
  yaw.attach(27); 
  yaw.write(95);
}



void loop() {
bluetooth();
}
