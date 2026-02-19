#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <lesson-22.hpp>

static LiquidCrystal_I2C lcd(0x27, 16, 2);

static DHT dht(2,DHT11);

void LCD_print::init()
{
    lcd.begin(8, 2);
    lcd.backlight();
}
void LCD_print::update()
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LMAO");
    lcd.setCursor(0, 1);
    lcd.print("The best");
    delay(1000);
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("LMAO");
    lcd.setCursor(0, 0);
    lcd.print("The best");
    delay(1000);
}
void DHT_print::init(){
    Serial.begin(9600);
    dht.begin();
}
void DHT_print::update(){
    Serial.println(dht.readHumidity());
    delay(100);
}