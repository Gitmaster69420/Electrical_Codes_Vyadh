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

#define buttons 13
/*
#define joy2_x 26
#define joy2_y 27

#define joy3_x 14
#define joy3_y 12

#define but_1 32
#define but_2 35
#define but_3 34
#define but_4 39
#define but_5 36
*/



void setup() {

  //initializing pins
  // Joystick 1
  pinMode(joy1_x, INPUT);
  pinMode(joy1_y, INPUT);

  //buttons
  pinMode(buttons, INPUT)
/*
  // Joystick 2
  pinMode(joy2_x, INPUT);
  pinMode(joy2_y, INPUT);

  // Joystick 3
  pinMode(joy3_x, INPUT);
  pinMode(joy3_y, INPUT);

  //buttons
  pinMode(but_1, INPUT);
  pinMode(but_2, INPUT);
  pinMode(but_3, INPUT);
  pinMode(but_4, INPUT);
  pinMode(but_5, INPUT);
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

controllerData payload;

void loop() {

  // Joystick 1
  payload.joystick1_x = analogRead(joy1_x);
  payload.joystick1_y = analogRead(joy1_y);
  int button = analogRead(buttons);
  if (button == 4095) {
    payload.But = button;
  }

  else if ((button >=2900) && (button <= 3000)) {
    payload.But = button;
  }

  else if ((button >=1900) && (button <= 2000)) {
    payload.But = button;
  }

  else if ((button >= 800) && (button <= 900)) {
    payload.But = button;
  }

  else if (button == 0) {
    payload.But = button;
  }
/*
  // Joystick 2
  payload.joystick2_x = analogRead(joy2_x);
  payload.joystick2_y = analogRead(joy2_y);

  // Joystick 3
  payload.joystick3_x = analogRead(joy3_x);
  payload.joystick3_y = analogRead(joy3_y);

  //buttons
  payload.button_1 = digitalRead(but_1);
  payload.button_2 = digitalRead(but_2);
  payload.button_3 = digitalRead(but_3);
  payload.button_4 = digitalRead(but_4);
  payload.button_5 = digitalRead(but_5);
*/

  Serial.print(payload.joystick1_x);
  Serial.print(",");
  Serial.print(payload.joystick1_y);
  Serial.println("  ");

  Serial.print(payload.But);
  Serial.print(",");

/*
  Serial.print(payload.joystick2_x);
  Serial.print(",");
  Serial.print(payload.joystick2_y);
  Serial.println("  ");

  Serial.print(payload.joystick3_x);
  Serial.print(",");
  Serial.print(payload.joystick3_y);
  Serial.println("  ");

  Serial.print(payload.button_1);
  Serial.print(",");
  Serial.print(payload.button_2);
  Serial.print(",");
  Serial.print(payload.button_3);
  Serial.print(",");
  Serial.print(payload.button_4);
  Serial.print(",");
  Serial.print(payload.button_5);
  Serial.println("  ");
*/
  Serial.println("  ");
  Serial.println("  ");
  Serial.println("  ");

  radio.write(&payload, sizeof(payload));

  delay(100);

}
