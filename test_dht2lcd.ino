/*
TEST DHT11 & LCD1602
 */
//#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

//here we use 14 of ESP32 to read data
#define DHTPIN 14

//our sensor is DHT11 type
#define DHTTYPE DHT11

//create an instance of DHT sensor
DHT dht(DHTPIN, DHTTYPE);
 

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  // initialize the lcd 
  lcd.init();
  lcd.backlight();
  //Serial.begin(9600);
  Serial.begin(115200);
  Serial.println("Start!");
  //call begin to start sensor
  dht.begin();
  //
}

void loop()
{
  /*
   * DHT11 read temp. & humid.
  */
  //use the functions which are supplied by library.
  int h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  int t = dht.readTemperature();
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  }
  // print the result to Terminal
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" *C");
  
  // clear the screen
  lcd.clear();
  // display each character to the LCD
  lcd.print("Yuki Temp.:");
  lcd.print(t);
  lcd.println("*C");
  lcd.setCursor(0, 1);
  lcd.print("     Humid.: ");
  lcd.print(h);
  lcd.println("%");
  // 2sec delay  
  delay(1000);
}
