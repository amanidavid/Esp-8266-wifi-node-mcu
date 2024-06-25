#include "BackendCommunicator.h"
#include <WiFiClientSecure.h>

void BackendCommunicator::sendData(const String& cardUid) {
    // WiFiClientSecure client;
    // client.setInsecure();  // Allow connections to sites with invalid certificates

    Serial.println(serverUrl);
    // Construct the full URL for sending the data
    String url = String(serverUrl) + "/test"; // Adjust the endpoint based on your Laravel application

    // Construct the data payload
    String payload = cardUid;
 Serial.println(payload);
    // Send HTTP POST request with the payload
    // HTTPClient https;
    HTTPClient http;
    
    http.begin(client, url);  // Use the WiFiClient with the URL
    http.addHeader("Content-Type", "text/plain");
    int httpCode = http.POST(payload);

    if (httpCode > 0) {
        Serial.printf("HTTP Response code: %d\n", httpCode);
        String response = http.getString();
        Serial.println(http.getString());
    } else {
        Serial.printf("Error sending request: %s\n", http.errorToString(httpCode).c_str());
        Serial.print("HTTP Response code: ");
        Serial.println(httpCode);
        String response = http.getString();


    }
    http.end();
}
