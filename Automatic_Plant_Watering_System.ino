#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  pinMode(3, OUTPUT); //output pin for relay board, this will sent signal to the relay
  pinMode(6, INPUT); //input pin coming from soil sensor
  //techpassion
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(3, OUTPUT);
  digitalWrite(3, HIGH);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("IRRIGATION");
  lcd.setCursor(0, 1);
  lcd.print("SYSTEM IS ON ");
  lcd.print("");
  delay(3000);
  lcd.clear();
}

void loop() {
   int water = digitalRead(6);  // reading the coming signal from the soil sensor
  Serial.println(water);
  if (water == HIGH) // if water level is full then cut the relay
  {
    digitalWrite(3, LOW); // low is to cut the relay
    lcd.setCursor(0, 0);
    lcd.print("Water Pump is ON ");
  }
  else
  {
    digitalWrite(3, HIGH); //high to continue proving signal and water supply
    lcd.setCursor(0, 0);
    lcd.print("Water Pump is OFF");
  }
  delay(400);
}
