#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

int water = A0;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
}

void loop() {
  lcd.clear();
  int val = analogRead(water);
  lcd.print("Water level: ");
  lcd.print(val);
  delay(1000);
}
