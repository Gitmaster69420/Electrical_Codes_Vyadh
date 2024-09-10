#include <SoftwareSerial.h>

const int RX_PIN = 32; // Replace with your RX pin
const int TX_PIN = 33; // Replace with your TX pin

SoftwareSerial MySerial(RX_PIN, TX_PIN); // RX, TX

void setup() {
  MySerial.begin(9600); // Start software serial at 9600 bps
  Serial.begin(9600); // Start hardware serial for debugging

  Serial.println("Starting latency test...");
  delay(2000); // Give time for setup
}

void loop() {
  unsigned long startTime = millis(); // Record the time before sending data

  // Send the timestamp
  MySerial.println(startTime);

  // Wait for the acknowledgment from the receiver
  while (!MySerial.available());

  unsigned long receivedTime = MySerial.parseInt(); // Receive the acknowledgment time

  unsigned long roundTripTime = millis() - startTime; // Calculate round-trip time
  Serial.print("Round-trip time: ");
  Serial.print(roundTripTime);
  Serial.println(" ms");

  delay(1000); // Wait before the next test
}
