#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define ledPin 15
#define ledNum 4
int lux;
int R[4] = {0, 10, 50, 10}, G[4] = {0, 10, 50, 10}, B[4] = {0, 10, 50, 10};
int Neo[4] = {0, 1, 3, 2};
int j = 0;

Adafruit_NeoPixel pixels(ledNum, ledPin, NEO_GRB + NEO_KHZ800);

void setup()
{
  Serial.begin(115200);
  pixels.begin();
  delay(1000);
  Serial.println("Starting NeoPixel");
}

void loop()
{
  R[0] = random(0, 255) * 0.1;
  G[0] = random(0, 255) * 0.1;
  B[0] = random(0, 255) * 0.1;
  pixels.setPixelColor(Neo[3], pixels.Color(R[3], G[3], B[3]));

  R[3] = R[2];
  G[3] = G[2];
  B[3] = B[2];
  pixels.setPixelColor(Neo[2], pixels.Color(R[2], G[2], B[2]));

  R[2] = R[1];
  G[2] = G[1];
  B[2] = B[1];
  pixels.setPixelColor(Neo[1], pixels.Color(R[1], G[1], B[1]));

  R[1] = R[0];
  G[1] = G[0];
  B[1] = B[0];
  pixels.setPixelColor(Neo[0], pixels.Color(R[0], G[0], B[0]));

  pixels.show();
  delay(1000);
}