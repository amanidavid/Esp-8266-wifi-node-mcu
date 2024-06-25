#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password)
  : ssid(ssid), password(password) {}

void WiFiManager::connect() {
  Serial.println();
  Serial.println("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void WiFiManager::reconnectIfNeeded() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi not connected, attempting to reconnect...");
    connect();
  }
}
