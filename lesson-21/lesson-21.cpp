#include <lesson-21.hpp>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

static LiquidCrystal_I2C lcd(0x27, 16, 2);

void LCD_Print::init()
{
    lcd.begin(8,2);
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Cat");
    lcd.setCursor(0, 1);
    lcd.print("Robocode");
}
void LCD_Print::update()
{
}