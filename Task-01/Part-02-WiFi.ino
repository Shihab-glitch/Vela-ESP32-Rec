#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C mon(0x27, 16, 2);

void setup() 
{
  Serial.begin(115200);
  mon.begin();
  mon.backlight();
  mon.clear();
  mon.printf("Scanning...");

}

void loop() 
{
  int n = WiFi.scanNetworks();

  mon.clear();
  mon.printf("Wi-Fi Found: %d", n);

  if (n == 0) 
  {
    mon.setCursor(0, 1);
    mon.printf("No networks found.");
  } 
  else 
  {
    for (int i = 0; i < n; ++i) 
    {
      mon.setCursor(0, 1);
      mon.printf("%d)%s", i + 1, WiFi.SSID(i).substring(0, 16));

      delay(2000);
      mon.clear();
      mon.printf("Wi-Fi Found: %d", n);
    }
    delay(2000);
    mon.clear();
    mon.printf("Again Scanning..");
  }
  delay(1000);
}