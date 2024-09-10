//#################################
//#################################

//Reciever code

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

struct controllerpayload{
  int joystick1_x;
  int joystick1_y;

  int But;
/*
  int joystick2_x;
  int joystick2_y;

  int joystick3_x;
  int joystick3_y;

  bool button_1;
  bool button_2;
  bool button_3;
  bool button_4;
  bool button_5;
*/
};


void loop() {
  
  controllerpayload payload;
  uint8_t pipe1;  //create a buffer to which the 1st pipe writes to
  if (radio.available(&pipe1)){  //see if there are any bytes available to read on pipe1
    Serial.println("payload available:");
    uint8_t	length = radio.getDynamicPayloadSize(); //get the length of the payload from RX FIFO pipe
    Serial.println(length);
    radio.read(&payload, length); //read the from the pipe the length of the payload from the above line

    //printing the joystick values:

    Serial.print("Joystick1 X: "); Serial.print(payload.joystick1_x);
    Serial.print(", Joystick1 Y: "); Serial.println(payload.joystick1_y);

    Serial.print("button value: "); Serial.print(payload.But); Serial.print(", ");
    /*
    Serial.print("Joystick2 X: "); Serial.print(payload.joystick2_x);
    Serial.print(", Joystick2 Y: "); Serial.println(payload.joystick2_y);
    
    Serial.print("Joystick3 X: "); Serial.print(payload.joystick3_x);
    Serial.print(", Joystick3 Y: "); Serial.println(payload.joystick3_y);

    //button values
    Serial.print("button 1: "); Serial.print(payload.button_1); Serial.print(", ");
    Serial.print("button 2: "); Serial.print(payload.button_2); Serial.print(", ");
    Serial.print("button 3: "); Serial.print(payload.button_3); Serial.print(", ");
    Serial.print("button 4: "); Serial.print(payload.button_4); Serial.print(", ");
    Serial.print("button 5: "); Serial.print(payload.button_5);
*/
    
    Serial.println("  ");
    Serial.println("  ");
    Serial.println("  ");
    }

  //else {
  //  Serial.println(-1);
  //}

}
