#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mon(0x27, 16, 2);

const char* message1_line1 = "Hello, All!";
const char* message1_line2 = "From Team Vela.";

const char* message2_line1 = "Let's Learn.";
const char* message2_line2 = "Let's Build.";

const char* message3_line1 = "Have a good day.";
const char* message3_line2 = "Goodbye !!!";

void setup() 
{
  Serial.begin(115200);
  mon.begin();
  mon.backlight();
  mon.clear();
}

void loop() 
{
  mon.clear();
  mon.setCursor(0, 0);
  mon.print(message1_line1);
  mon.setCursor(0, 1);
  mon.print(message1_line2);
  delay(2000);

  mon.clear();
  mon.setCursor(0, 0);
  mon.print(message2_line1);
  mon.setCursor(0, 1);
  mon.print(message2_line2);
  delay(2000);

  mon.clear();
  mon.setCursor(0, 0);
  mon.print(message3_line1);
  mon.setCursor(0, 1);
  mon.print(message3_line2);
  delay(2000);
}