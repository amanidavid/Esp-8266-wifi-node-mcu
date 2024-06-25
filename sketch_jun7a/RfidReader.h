#ifndef RFID_READER_H
#define RFID_READER_H

#include <SPI.h>
#include <MFRC522.h>
// #include <unordered_map>

class RFIDReader {
public:
  RFIDReader(uint8_t ssPin, uint8_t rstPin);
  void begin();
  String readCard();

private:
  MFRC522 mfrc522;
};

#endif // RFID_READER_H
