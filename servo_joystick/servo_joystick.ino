#include <Servo.h>

Servo myservo;

int xInput = A0;
int xValue = 0;

int servoAngle = 90;
int speed = 10;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  xValue = analogRead(xInput);
  
  if (xValue < 100) {
    servoAngle -= speed;
    servoAngle = (servoAngle < 0) ? 0 : servoAngle;
    myservo.write(servoAngle);
  }
  else if (xValue > 900) {
    servoAngle += speed;
    servoAngle = (servoAngle > 180) ? 180 : servoAngle;
    myservo.write(servoAngle);
  }

  Serial.println(xValue);
  Serial.println(servoAngle);
  delay(200);
}
