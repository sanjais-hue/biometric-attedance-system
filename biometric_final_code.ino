#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Blynk Authentication Token (from the Blynk app/email)
char auth[] = "YourAuthToken";

// Wi-Fi credentials
char ssid[] = "your_SSID";
char pass[] = "your_PASSWORD";

// Relay pin (connected to GPIO 5, which is D1 on NodeMCU)
const int relayPin = 5;

void setup() {
  // Start the Serial communication
  Serial.begin(115200);

  // Set the relay pin as output
  pinMode(relayPin, OUTPUT);
  
  // Set relay to OFF initially
  digitalWrite(relayPin, LOW);

  // Connect to Blynk server and Wi-Fi
  Blynk.begin(auth, ssid, pass);
}

void loop() {
  // Keep Blynk running
  Blynk.run();
}

// Blynk function to control relay based on button widget state
BLYNK_WRITE(V1) {
  int pinValue = param.asInt(); // Get value from virtual pin V1
  
  if (pinValue == 1) {
    digitalWrite(relayPin, HIGH); // Turn relay ON
    Serial.println("Relay ON");
  } else {
    digitalWrite(relayPin, LOW);  // Turn relay OFF
    Serial.println("Relay OFF");
  }
}
