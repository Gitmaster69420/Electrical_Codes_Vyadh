//


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(4, 5);  // CE, CSN


byte address[6] = "00001";


void setup() {


  //begining the module/library
  if (!radio.begin()) {
  Serial.println(F("radio hardware not responding!"));
  while (1) {} // hold program in infinite loop to prevent subsequent errors
  }


  Serial.begin(115200);
  Serial.println("start");


  //the RF module's power level:
  //Options: RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH, RF24_PA_MAX
  radio.setPALevel(RF24_PA_HIGH);


  //opening reading "pipe" no.1 at the given address
  radio.openReadingPipe(1, address);


  //setting this RF module to recieve mode:
  radio.startListening();
}


int payload;


void loop() {
 
  uint8_t pipe1;  //create a buffer to which the 1st pipe writes to
  if (radio.available(&pipe1)){  //see if there are any bytes available to read on pipe1
  Serial.println("payload available:");
  uint8_t length = radio.getDynamicPayloadSize(); //get the length of the payload from RX FIFO pipe
  radio.read(&payload, length); //read the from the pipe the length of the payload from the above line
  Serial.println(payload);
  payload = 0; //reset the payload to zero
  }


}


