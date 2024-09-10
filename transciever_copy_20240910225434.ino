//#################################
//#################################


//transmitter code


#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>


RF24 radio(4, 5);  // CE, CSN


byte address[6] = "00001";


#define joy1_x 27
#define joy1_y 14
#define joy1_s 12


//temp
/*


#define joy2_x 26
#define joy2_y 27
#define joy2_s 14


#define joy3_x 12
#define joy3_y 13
#define joy3_s 11
*/




void setup() {


  //initializing pins
  // Joystick 1
  pinMode(joy1_x, INPUT);
  pinMode(joy1_y, INPUT);
  pinMode(joy1_s, INPUT);


  /* temp


  // Joystick 2
  pinMode(joy2_x, INPUT);
  pinMode(joy2_y, INPUT);
  pinMode(joy2_s, INPUT);


  // Joystick 3
  pinMode(joy3_x, INPUT);
  pinMode(joy3_y, INPUT);
  pinMode(joy3_s, INPUT);
  */




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


struct controllerData{
  int joystick1_x;
  int joystick1_y;
  bool joystick1_s;


  /* temp


  int joystick2_x;
  int joystick2_y;
  bool joystick2_s;


  int joystick3_x;
  int joystick3_y;
  bool joystick3_s;


  */
};


controllerData payload;


void loop() {


  // Joystick 1
  payload.joystick1_x = analogRead(joy1_x);
  payload.joystick1_y = analogRead(joy1_y);
  payload.joystick1_s = digitalRead(joy1_s);


  /* temp


  // Joystick 2
  payload.joystick2_x = analogRead(joy2_x);
  payload.joystick2_y = analogRead(joy2_y);
  payload.joystick2_s = digitalRead(joy2_s);


  // Joystick 3
  payload.joystick3_x = analogRead(joy3_x);
  payload.joystick3_y = analogRead(joy3_y);
  payload.joystick3_s = digitalRead(joy3_s);


  */;


  //temp:
  Serial.print(payload.joystick1_x);
  Serial.print(",");
  Serial.println(payload.joystick1_y);


  radio.write(&payload, sizeof(payload));


  delay(100);




}
