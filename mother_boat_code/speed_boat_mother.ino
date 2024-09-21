#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial BTSerial(11, 12);
Servo elvo, left, right;

#define left_motor_forward 4
#define left_motor_backward 2
#define right_motor_forward 7
#define right_motor_backward 8
#define left_motor_speed 3
#define right_motor_speed 9
#define spl 25
#define spr 25
#define led 13

void setup() {
  pinMode (led, OUTPUT);
  Serial.begin(115200);
  BTSerial.begin(9600);
  pinMode(left_motor_forward, OUTPUT);
  pinMode(left_motor_backward, OUTPUT);
  pinMode(left_motor_speed, OUTPUT);
  pinMode(right_motor_forward, OUTPUT);
  pinMode(right_motor_backward, OUTPUT);
  pinMode(right_motor_speed, OUTPUT);

  elvo.attach(10);
  elvo.write(100);
  
  left.attach(6);
  right.attach(5);
  left.write(180); 
  right.write(0);
}

void loop() {
  bluetooth();
  //motor(10 * spl, 10 * spr);
}
