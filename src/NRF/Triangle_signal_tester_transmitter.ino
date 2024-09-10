//transmitter code


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(4, 5);  // CE, CSN


byte address[6] = "00001";


void setup() {


  // begining the module/library
  if (!radio.begin()) {
  Serial.println(F("radio hardware not responding!"));
  while (1) {} // hold program in infinite loop to prevent subsequent errors
  }


  Serial.begin(115200);
  Serial.println("start");


  //the RF module's power level:
  //Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setPALevel(RF24_PA_HIGH);


  //setting this RF module to transmit mode:
  radio.stopListening();


  // Open the writing pipe with the defined address
  // This is the address the data will be sent to
  // use a different address if you wanna send the data to a different module.
  radio.openWritingPipe(address);


}


int payload; //variable to hold the data to be sent


void loop() {


  //simple code. will incriment the sent values from 0 to 100 then back to 0 and repeats.


  for (payload = 0; payload <= 100; payload++) {
    radio.write(&payload, sizeof(payload));
    Serial.println(payload);
    delay(100);
  }


  for (payload = 100; payload >= 0; payload--) {
    radio.write(&payload, sizeof(payload));
    Serial.println(payload);
    delay(100);
  }
}
