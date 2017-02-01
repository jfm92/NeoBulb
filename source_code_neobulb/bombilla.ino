/*******************************************
 * Proyecto realizado por Juan Flores Muñoz
 * Electronica Creativa
 * 4º GISE
 *******************************************/


#include <Adafruit_NeoPixel.h>
#include <SimpleDHT.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

//Configuration Neopixel
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 4           
#define NUMPIXELS      21
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Configuration DHT11(Temp and humidity sensor)
int pinDHT11 = 5;
SimpleDHT11 dht11;

SoftwareSerial PSerial(1, 2);

//configuration EEPROM
int dir=0;
//it's neccesary to divide dir, because you can only write in eeprom byte once time
byte b_red;//1byte can load 0 to 255
byte b_green;//1byte can load 0 to 255
byte b_blue;//1byte can load 0 to 255

byte inicio;//to know if it's first time that it's load

void setup() {
  
  PSerial.begin(9600);
  pixels.begin();
  init_conf();//set the preconfigure value to initalitation
}

void loop() {
  rCommand();//read input from serial port and analyze wich command is receiving
}
