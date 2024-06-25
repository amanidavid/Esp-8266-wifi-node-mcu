#include <ESP8266WiFi.h>
#include <SPI.h>
#include <MFRC522.h>
#include "WiFiManager.h"
#include "RFIDReader.h"
#include "BackendCommunicator.h"

// WiFi credentials
const char* ssid = "Man";
const char* password = "amani012e";

// Define the base URL for your backend server
// const char* serverUrl = " https://7d90-197-250-130-247.ngrok-free.app";
const char* serverUrl = "http://172.20.10.3:8000/api";

// RFID reader connections
#define RST_PIN D1 // Reset pin for RFID reader (GPIO 5)
#define SS_PIN  D2 // Slave Select pin for RFID reader (GPIO 2)

// // RFID reader connections
// #define RST_PIN D3 // Reset pin for RFID reader (GPIO 5)
// #define SS_PIN  D4 // Slave Select pin for RFID reader (GPIO 2)

WiFiManager wifiManager(ssid, password);
RFIDReader rfidReader(SS_PIN, RST_PIN);

BackendCommunicator backendCommunicator(serverUrl);

void setup() {
  Serial.begin(9600);
  delay(10);

  // Connect to WiFi
  wifiManager.connect();

  // Initialize RFID reader
  rfidReader.begin();
}

void loop() {
  // Check WiFi connection status and reconnect if needed
  wifiManager.reconnectIfNeeded();

  // Read RFID card
  // rfidReader.readCard();
  // Read RFID card
    String cardUid = rfidReader.readCard(); // Read the card UID

    // Check if a card was successfully read
    if (!cardUid.isEmpty()) {
        // Send the card UID to the backend server
        backendCommunicator.sendData(cardUid.c_str());
    }

  delay(1000);
}
