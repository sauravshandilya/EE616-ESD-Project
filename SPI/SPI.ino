/*
 * Opearing Frequency = 16 MHz
 * 
 */

#include "SPI.h" // necessary library

word outputValue = 0; // a word is a 16-bit number
byte data = 0; // and a byte is an 8-bit number
void setup()
{
  //set pin(s) to input and output
  pinMode(SS, OUTPUT);
  pinMode(SCK, OUTPUT);
  pinMode(MOSI, OUTPUT);
  
  SPI.setBitOrder(MSBFIRST);
  SPI.setDataMode(SPI_MODE3);     // set SPI data mode clock polarity = 1 and clock phase = 1
  SPI.setClockDivider(SPI_CLOCK_DIV8); // default is divide by 16MHz/8 = 2MHz
  SPI.begin();                   // wake up the SPI bus.
  digitalWrite(SS, HIGH);        // initially SS is kept high
}
 
void loop()
{
  //for (int a=0; a<=4096; a=a+100)
  //{
    int a = 4095;
    outputValue = a;
    digitalWrite(SS, LOW);
    data = highByte(outputValue);
    data = 0b00001111 & data;
    data = 0b00110000 | data;
    SPI.transfer(data);
    data = lowByte(outputValue);
    SPI.transfer(data);
    digitalWrite(SS, HIGH);
    delay(1000);
  //}
}
