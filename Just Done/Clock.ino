#include <WiFi.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "  ";
const char* pass = "  ";

const char* server = "pool.ntp.org";
const long  gmtch = 21600;

LiquidCrystal_I2C scr(0x27, 16, 2);

WiFiUDP ntpUDP;
NTPClient timer(ntpUDP, server, gmtch);

int s, m, h, d, mo, y;

void setup() 
{
  Serial.begin(115200);
  scr.begin();
  scr.backlight();
  WiFi.begin(ssid, pass);
  timer.begin();
}

void loop() 
{
  timer.update();

  long Time = timer.getEpochTime();
  s = second(Time);
  m = minute(Time);
  h = hour(Time);
  d = day(Time);
  mo = month(Time);
  y = year(Time);

  char timeshow[30];
  sprintf(timeshow, "%02d:%02d:%02d", h, m, s);
  scr.setCursor(0, 0);
  scr.printf(timeshow);

  char dateshow[30];
  sprintf(dateshow, "%02d-%02d-%04d", d, mo, y);
  scr.setCursor(0, 1);
  scr.printf(dateshow);

  delay(1000);
}
