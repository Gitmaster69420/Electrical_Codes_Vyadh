#include <HardwareSerial.h>

HardwareSerial MySerial(1); // Use UART1 for HC12

const int RX_PIN = 32; // Replace with your RX pin
const int TX_PIN = 33; // Replace with your TX pin
const int DATA_SIZE = 10240; // 10 KB of data

void setup() {
  MySerial.begin(9600, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial.begin(9600); // Serial monitor for debugging

  Serial.println("Starting transmission...");
  delay(2000); // Give time for setup
}

void loop() {
  unsigned long startTime = millis();

  for (int i = 0; i < DATA_SIZE; i++) {
    MySerial.write('A'); // Send a block of 'A' characters
  }

  // Wait for acknowledgment from the receiver
  while (!MySerial.available()) {}

  unsigned long endTime = millis();
  unsigned long timeTaken = endTime - startTime;

  float dataRate = (DATA_SIZE * 8.0) / (timeTaken / 1000.0); // Bits per second (bps)
  Serial.print("Data rate: ");
  Serial.print(dataRate);
  Serial.println(" bps");

  delay(5000); // Wait before next test
}
