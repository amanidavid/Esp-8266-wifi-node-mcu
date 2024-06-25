#include "RfidReader.h"

RFIDReader::RFIDReader(uint8_t ssPin, uint8_t rstPin)
  : mfrc522(ssPin, rstPin) {}

void RFIDReader::begin() {
  SPI.begin(); 
  mfrc522.PCD_Init(); 
  Serial.println("Scan a card to see its UID...");
}

String RFIDReader::readCard() {
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
        String uidStr = "";

        // Concatenate each byte of the UID in hexadecimal format to uidStr with spaces
        for (byte i = 0; i < mfrc522.uid.size; i++) {
            if (i > 0) {
                uidStr += " "; // Add a space between bytes
            }
            if (mfrc522.uid.uidByte[i] < 0x10) {
                uidStr += "0"; // Add leading zero if necessary
            }
            uidStr += String(mfrc522.uid.uidByte[i], HEX);
        }
        
        Serial.print("Card UID: ");
        Serial.println(uidStr);

      
        
        mfrc522.PICC_HaltA();
        
       return uidStr;
    }
    
    return ""; // Return empty string if no card is present or read fails
}


