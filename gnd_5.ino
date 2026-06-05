#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 2
#define DHTTYPE DHT11
#define BUZZER 8

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(BUZZER, OUTPUT);

  lcd.init();
  lcd.backlight();

  dht.begin();

  lcd.setCursor(0,0);
  lcd.print("Greenhouse");
  lcd.setCursor(0,1);
  lcd.print("Monitoring");
  delay(2000);
  lcd.clear();
}

void loop() {

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();

  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.print(temp);
  lcd.print(" C ");

  lcd.setCursor(0,1);
  lcd.print("H:");
  lcd.print(hum);
  lcd.print("% ");

  if(temp > 35){
    digitalWrite(BUZZER, HIGH);
  }
  else{
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}