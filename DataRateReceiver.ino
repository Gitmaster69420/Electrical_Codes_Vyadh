#include <HardwareSerial.h>

HardwareSerial MySerial(1); // Use UART1 for HC12

const int RX_PIN = 32; // Replace with your RX pin
const int TX_PIN = 33; // Replace with your TX pin

void setup() {
  MySerial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial.begin(9600); // Serial monitor for debugging

  Serial.println("Ready to receive...");
}

void loop() {
  int bytesReceived = 0;
  unsigned long startTime = millis();

  while (bytesReceived < 10240) {
    if (MySerial.available()) {
      MySerial.read(); // Read the incoming byte
      bytesReceived++;
    }
  }

  // Acknowledge by sending back a character
  MySerial.write('B');
  
  Serial.print("Received 10 KB of data in ");
  Serial.print(millis()-startTime);
  Serial.println(" ms");

  delay(5000); // Wait before next test
}
