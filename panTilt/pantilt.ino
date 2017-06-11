#include <Servo.h>
Servo myservo;

#define pinoPan a3
#define pinoTilt a2

int posPan = 0;
int posTilt = 0;

void setup() {
  pan.attach(pinoPan);
  tilt.attach(pinoTilt);
}

void loop() {
  for (pos = 110; pos <= 180; pos += 1) {
    myservo.write(pos);
    delay(15);
  }
  for (pos = 180; pos >= 110; pos -= 1) {
    myservo.write(pos);
    delay(15);
  }
}

