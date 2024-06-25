#ifndef BACKEND_COMMUNICATOR_H
#define BACKEND_COMMUNICATOR_H

#include <Arduino.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>

class BackendCommunicator {
private:
     const char* serverUrl;
     WiFiClient client;

public:
    BackendCommunicator(const char* serverUrl): serverUrl(serverUrl) {};

    void sendData(const String& cardUid);
};

#endif
