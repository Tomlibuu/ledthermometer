#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>
#define red 9
#define green 10
#define blue 11

const int SENSOR_PIN = 13;
OneWire oneWire(SENSOR_PIN);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x27, 16, 2);
float tempCelsius;

void setup()
{
  sensors.begin();
  lcd.init();
  lcd.backlight();
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  
}

void loop()
{
  //Read temperature from sensor
  sensors.requestTemperatures();
  tempCelsius = sensors.getTempCByIndex(0);

  //Print to LCD screen text "Temperature" and temperature in Celsius from sensor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print(tempCelsius);
  lcd.print((char)223);
  lcd.print("C");

  //Rows under change led strip colors according to temperature fluctuations
  
  if(tempCelsius >= 30){
    analogWrite(red, 102);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
  if(tempCelsius >= 25 && tempCelsius < 30){
    analogWrite(red, 255);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
  if(tempCelsius >= 20 && tempCelsius < 25){
    analogWrite(red, 255);
    analogWrite(green, 140);
    analogWrite(blue, 0);
  }
  if(tempCelsius >= 15 && tempCelsius < 20){
    analogWrite(red, 102);
    analogWrite(green, 102);
    analogWrite(blue, 0);
  }  
  if(tempCelsius >= 10 && tempCelsius < 15){
    analogWrite(red, 0);
    analogWrite(green, 102);
    analogWrite(blue, 0);
  }
  if(tempCelsius >= 5 && tempCelsius < 10){
    analogWrite(red, 0);
    analogWrite(green, 255);
    analogWrite(blue, 0);
  }
  if(tempCelsius > -5 && tempCelsius < 5){
    analogWrite(red, 0);
    analogWrite(green, 204);
    analogWrite(blue, 204);
  }
  if(tempCelsius > -15 && tempCelsius <= -5){
    analogWrite(red, 0);
    analogWrite(green, 102);
    analogWrite(blue, 204);
  }
  if(tempCelsius > -20 && tempCelsius <= -15){
    analogWrite(red, 0);
    analogWrite(green, 0);
    analogWrite(blue, 255);
  }
  if(tempCelsius > -30 && tempCelsius <= -20){
    analogWrite(red, 204);
    analogWrite(green, 0);
    analogWrite(blue, 204);
  }
  if(tempCelsius <= -30){
    analogWrite(red, 102);
    analogWrite(green, 0);
    analogWrite(blue, 102);
  }

  delay(1000);
}