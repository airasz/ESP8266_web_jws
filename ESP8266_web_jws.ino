/*
    HTTP over TLS (HTTPS) example sketch
    This example demonstrates how to use
    WiFiClientSecure class to access HTTPS API.
    We fetch and display the status of
    esp8266/Arduino project continuous integration
    build.
    Limitations:
      only RSA certificates
      no support of Perfect Forward Secrecy (PFS)
      TLSv1.2 is supported since version 2.4.0-rc1
    Created by Ivan Grokhotkov, 2015.
    This example is in public domain.
config: board: generic esp8266 1st index



*/

// this line add in windows

#include <ESP8266WiFi.h>
// #include <ESP8266WiFiMulti.h>
#include <WiFiClientSecure.h>

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>

#define TFT_CS     5
#define TFT_RST    16  // you can also connect this to the Arduino reset
                       // in which case, set this #define pin to -1!
#define TFT_DC     2
#define TFT_SCLK 0   // set these to be whatever pins you like!
#define TFT_MOSI 4   // set these to be whatever pins you like!
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);


#ifndef STASSID
#define STASSID "XZ5C"
#define STAPSK  "air46664"
#endif
#define pinBL 12

// ESP8266WiFiMulti wifimulti;

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "www.dream.co.id";
const int httpsPort = 443;   //443
 WiFiClientSecure client;


 
// Use web browser to view and copy
// SHA1 fingerprint of the certificate
const char fingerprint[] PROGMEM = "36 91 7F 63 0D CA 86 8D 9E 4C CC B8 48 A6 A9 AF A0 5D 68 43";