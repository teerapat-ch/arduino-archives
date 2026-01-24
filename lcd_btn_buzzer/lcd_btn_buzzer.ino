#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

const int btn = 6;
const int bzr = 5;

int lastBtnState = 1;
int btnState = 1;

int textNum = 1;

void setup() {
  Serial.begin(9600);

  pinMode(btn, INPUT_PULLUP);
  pinMode(bzr, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  btnState = digitalRead(btn);
  if (btnState == LOW && lastBtnState == HIGH) {
    //tone(bzr, 4000, 100);
    if (textNum < 3) {
      textNum++;
    }
    else {
      textNum = 1;
    }

    lcd.clear();

    const char* displayTxt;
    switch (textNum) {
      case 1:
        displayTxt = "First Text";
        break;
      case 2:
        displayTxt = "Second Text";
        break;
      case 3:
        displayTxt = "Third Text";
        break;
      default:
        displayTxt = "Error!";
    }
    lcd.print(displayTxt);
    delay(200);
  }

  lastBtnState = btnState;
}
