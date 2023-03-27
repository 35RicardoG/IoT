#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int ledPin = 13;
int detectorPin = 2;
int value;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(detectorPin, INPUT);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  value = digitalRead(detectorPin);

  if (value == HIGH) {
    digitalWrite(ledPin, HIGH);
    lcd.print("Objeto detectado");
  } else {
    digitalWrite(detectorPin, LOW);
    lcd.print("No hay objeto");
  }

  delay(500);
  lcd.clear;
}
