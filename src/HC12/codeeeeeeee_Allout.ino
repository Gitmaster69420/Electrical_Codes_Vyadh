#include <SoftwareSerial.h>

SoftwareSerial HC12(22,23); //RX,TX

void setup() {
  pinMode(34,INPUT); //J1x
  pinMode(35,INPUT); //j1y
  pinMode(32,INPUT); //butt1
  pinMode(33,INPUT); //j2x
  pinMode(25,INPUT); //j2y
  pinMode(27,INPUT); //j3x
  pinMode(14,INPUT); //j3y
  pinMode(13,INPUT); //butt2
  pinMode(19,INPUT); //w
  pinMode(18,INPUT); //a
  pinMode(5,INPUT);  //s
  pinMode(17,INPUT); //d
  pinMode(16,INPUT); //stop
  pinMode(4,INPUT);  //butt3
  pinMode(15,INPUT); //butt4

  Serial.begin(9600);
  HC12.begin(9600);
}

void loop() {
String message;

int j1x = analogRead(34);
int j1y = analogRead(35);
int j2x = analogRead(33);
int j2y = analogRead(25);
int j3x = analogRead(27);
int j3y = analogRead(14);

//Joystick1
if (j1x<700) {
message += "b1";
}
else if (j1x>3500) {
message += "f1";
}
if (j1y<700) {
message += "l1";
}
else if (j1y>3500) {
message += "r1";
}

//Joystick2
if (j2x<700) {
message += "b2";
}
else if (j2x>3500) {
message += "f2";
}
if (j2y<700) {
message += "l2";
}
else if (j2y>3500) {
message += "r2";
}

//Joystick3
if (j3x<700) {
message += "b3";
}
else if (j3x>3500) {
message += "f3";
}
if (j3y<700) {
message += "l3";
}
else if (j3y>3500) {
message += "r3";
}

//Buttons
if (digitalRead(19)) {
  message += "wb";
}
if (digitalRead(18)) {
  message += "ab";
}
if (digitalRead(5)) {
  message += "sb";
}
if (digitalRead(17)) {
  message += "db";
}
if (digitalRead(16)) {
  message += "Xb";
}
// else if (digitalRead(4)) {
//   m4 = "1b";
// }
// else if (digitalRead(15)) {
//   m4 = "2b";
// }
// else if (digitalRead(13)) {
//   m4 = "3b";
// }
// else if (digitalRead(21)) {
//   m4 = "4b";
// }

Serial.println(message);
HC12.println(message);

delay(200);

}