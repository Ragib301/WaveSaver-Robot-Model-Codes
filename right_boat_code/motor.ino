void motor(int a, int b){
  if(a>=0){
    digitalWrite(left_motor_forward, 1);
    digitalWrite(left_motor_backward, 0);
  }
  else{
    a=-a;
    digitalWrite(left_motor_forward, 0);
    digitalWrite(left_motor_backward, 1);
  }
  if(b>=0){
    digitalWrite(right_motor_forward, 1);
    digitalWrite(right_motor_backward, 0);
  }
  else{
    b=-b;
    digitalWrite(right_motor_forward, 0);
    digitalWrite(right_motor_backward, 1);
  }

  ledcWrite(ledChannel_x, b);
  ledcWrite(ledChannel_y, a);
  
}
