void bluetooth() {
  int s; //for adjustable speed system
  char x; //for storing receiving incoming data  
  
  while (1) { //infinite loop
    if (BTSerial.available() > 0) {
      x = BTSerial.read();
      Serial.println(x);
      
      if (x == 'F') motor(s * spl, 0 * spr);
      else if (x == 'B'){digitalWrite(8,1);digitalWrite(9,1);digitalWrite(7,0);}
      else if (x == 'L') elvo.write(100+s*8);
      else if (x == 'R') elvo.write(100-s*10);
      else if (x == 'S') {motor(0 * spl, 0 * spr);digitalWrite(8,0);digitalWrite(9,0);digitalWrite(7,0);}
      else if (x == 'W') {left.write(0); right.write(180);}
      else if (x == 'w') {left.write(180); right.write(0);}
      else if (x == 'U') digitalWrite(led, HIGH);
      else if (x == 'u') digitalWrite(led, LOW);
      else if (x == '0') s = 0;
      else if (x == '1') s = 1;
      else if (x == '2') s = 2;
      else if (x == '3') s = 3;
      else if (x == '4') s = 4;
      else if (x == '5') s = 5;
      else if (x == '6') s = 6;
      else if (x == '7') s = 7;
      else if (x == '8') s = 8;
      else if (x == '9') s = 9;
      else if (x == 'q') s = 10;
    }
  }
}
