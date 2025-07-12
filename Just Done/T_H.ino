#include <DHT.h>
#include <LiquidCrystal_I2C.h>

#define DHTPIN 5
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C mon(0x27, 16, 2);

void setup() 
{
  Serial.begin(115200);
  dht.begin();
  mon.begin();
  mon.backlight();
  mon.clear();
  mon.setCursor(0, 0);
  mon.printf("Starting...");
  delay(1000);
  mon.clear();
}

void loop() 
{
  delay(2000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h))
  {
    mon.clear();
    mon.setCursor(0, 0);
    mon.printf("Sensor Error");
  } 
  else 
  {
    mon.clear();
    mon.setCursor(0, 0);
    mon.printf("Temp: %.2f *C", t);
    mon.setCursor(0, 1);
    mon.printf("Humi: %.2f %%", h);
  }
}