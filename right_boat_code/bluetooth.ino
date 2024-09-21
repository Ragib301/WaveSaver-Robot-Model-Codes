
  void bluetooth() {
    
  int s; //for adjustable speed system
  char x; //for storing receiving incoming data  
  
  while (1) { //infinite loop
    if (SerialBT.available() > 0) {
      x = SerialBT.read();
      Serial.println(x);
      
      if (x == 'F'){motor(s * spl, s * spr); yaw.write(104);}
      else if (x == 'B'){motor(-s * spl, -s * spr); yaw.write(104);}
      else if (x == 'L') yaw.write(104+(90-s*5));
      else if (x == 'R') yaw.write(104-(90-s*5));
      else if (x == 'G') {motor(s * spl, s * spr); yaw.write(104+(90-s*5));}
      else if (x == 'I') {motor(s * spl, s * spr); yaw.write(104-(90-s*5));}
      else if (x == 'H') {motor(-s * spl, -s * spr); yaw.write(104+(90-s*5));}
      else if (x == 'J') {motor(-s * spl, -s * spr); yaw.write(104-(90-s*5));}
      else if (x == 'S') {motor(0, 0); yaw.write(104);}
      else if (x == 'W') digitalWrite(led, HIGH);
      else if (x == 'w') digitalWrite(led, LOW);

      
      else if (x == '0') s = 0;
      else if (x == '1') s = 1;
      else if (x == '2') s = 2;
      else if (x == '3') s = 3;
      else if (x == '4') s = 4;
      else if (x == '5') s = 5;
      else if (x == '6') s = 6;
      else if (x == '5') s = 5;
      else if (x == '8') s = 8;
      else if (x == '9') s = 9;
      else if (x == 'q') s = 10;
    }
  }
}
