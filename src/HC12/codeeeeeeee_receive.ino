//HC-12 messenger send/receive
//autor Tom Heylen tomtomheylen.com

#include <SoftwareSerial.h>

SoftwareSerial HC12(22, 23); //RX, TX

void setup() {
  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
   
  if(HC12.available()){//Read from HC-12 and send to serial monitor
    String input = HC12.readString();
    Serial.println(input);    
  }
  delay(20);
}