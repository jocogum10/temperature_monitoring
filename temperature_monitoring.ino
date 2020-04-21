#include <Arduino.h>
#include <Adafruit_SHT31.h>
#include <Wire.h>
#include <rgb_lcd.h>

rgb_lcd lcd;                             //importing LCD functions
Adafruit_SHT31 sht31 = Adafruit_SHT31(); //importing Sensor functions

void setup() {
  // Initialize LCD
  lcd.begin(16,2);
  // Initialize Temp Sensor
  sht31.begin(0x44);

  // Set LCD color (rrr, ggg, bbb)
  lcd.setRGB(255, 255, 255);
}

void loop() {

  // Variables for the temperature and humidity
  float temp = sht31.readTemperature();
  float hum = sht31.readHumidity();
  
  
  if (! isnan(temp)) {                    // check if 'is not a number'
    lcd.setCursor(0,0);                   //Set LCD cursor to first column, top row
    lcd.print("Temp *C = "); 
    lcd.print(temp);
  } else { 
    lcd.print("Failed to read temperature");
  }
  
  if (! isnan(hum)) {                     // check if 'is not a number'
    lcd.setCursor(0,1);                   //Set LCD cursor to first column, bottom row
    lcd.print("Hum. % = "); 
    lcd.print(hum);
  } else { 
    lcd.print("Failed to read humidity");
  }
  delay(1000);
}
