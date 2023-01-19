#include <Servo.h>

Servo servo1;
Servo servo2;
Servo servo3;
int pos = 0;
double multiplierR = 0.715; //regular multiplier
double multiplierC = 1.047; //claw multiplier
double angle = 180;

void setup() {
  servo1.attach(9);
  servo2.attach(8);
  servo3.attach(10);
}

void loop() {
  for(pos = 0; pos <= angle; pos += 1) {
    servo1.write(pos * multiplierC);
    servo2.write(pos * multiplierR);
    servo3.write(pos * multiplierC);
    delay(10);
  }
  delay(1000);
  for(pos = angle; pos >= 0; pos -= 1) {
    servo1.write(pos * multiplierC);
    servo2.write(pos * multiplierR);
    servo3.write(pos * multiplierC);
    delay(10);
  }
  delay(500);
}
