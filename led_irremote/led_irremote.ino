#include <IRremote.hpp>

const int blue = 7;
const int red = 6;
const int yellow = 5;

const int IR_RECEIVER_PIN = 12;

void setup() {
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVER_PIN, ENABLE_LED_FEEDBACK);

  pinMode(blue, OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
}

void loop() {
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    IrReceiver.printIRResultShort(&Serial);

    switch (IrReceiver.decodedIRData.decodedRawData) {
      case 0xE916FF00:
        Serial.println("OFF");
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        break;
      case 0xF30CFF00:
        Serial.println("Blue");
        digitalWrite(blue, HIGH);
        digitalWrite(red, LOW);
        digitalWrite(yellow, LOW);
        break;
      case 0xE718FF00:
        Serial.println("Red");
        digitalWrite(blue, LOW);
        digitalWrite(red, HIGH);
        digitalWrite(yellow, LOW);
        break;
      case 0xA15EFF00:
        Serial.println("Yellow");
        digitalWrite(blue, LOW);
        digitalWrite(red, LOW);
        digitalWrite(yellow, HIGH);
        break;
    }

    IrReceiver.resume();
  }
}
