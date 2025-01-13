/* 

17a: Print the WiFi RSSI of the ESP8266 to a ThingSpeak channel

17b: Add a two variable graph and fill it with either
• RSSI and LED on/off
• Data from two of your sensors
(you will need to add this to your breadboard)

17c: Explore the possibilities writing to and reading from ThingSpeak

*/
#include <WiFi.h>
#include <ThingSpeak.h>

// Wi-Fi credentials
const char* ssid = "Jarls Galaxy";
const char* pass = "jarlvep26";

// ThingSpeak settings
WiFiClient client;
unsigned long channelID = 2808163;        
const char* APIKey = "XS1Z5OLYIGIWYLPP";  
const int postDelay = 20 * 1000;         

// GPIO pin for the LED
const int ledPin = 2;
bool ledState = 0;

void setup() {
  Serial.begin(115200);

  // Initialize LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Start with LED off

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Get WiFi RSSI
  int rssi = WiFi.RSSI();
  Serial.print("RSSI: ");
  Serial.println(rssi);

  // Toggle LED state
  ledState = !ledState;  // Toggle state
  digitalWrite(ledPin, ledState);
  Serial.print("LED State: ");
  Serial.println(ledState ? "ON" : "OFF");


  // Set ThingSpeak fields
  ThingSpeak.setField(1, rssi);      // Field 1: WiFi RSSI
  ThingSpeak.setField(2, ledState);  // Field 2: LED state (1 for ON, 0 for OFF)

  // Post data to ThingSpeak
  int responseCode = ThingSpeak.writeFields(channelID, APIKey);
  if (responseCode == 200) {
    Serial.println("Data successfully sent to ThingSpeak!");
  } else {
    Serial.print("Error sending data. Response code: ");
    Serial.println(responseCode);
  }


  // Part 17c: Explore reading from ThingSpeak
  Serial.println("\nData successfully read from ThingSpeak!");
  float field1Data = ThingSpeak.readFloatField(channelID, 1);  // Read Field 1 data
  float field2Data = ThingSpeak.readFloatField(channelID, 2);  // Read Field 2 data
  Serial.print("Field 1 (RSSI): ");
  Serial.println(field1Data);
  Serial.print("Field 2 (LED State): ");
  Serial.println(field2Data);

  delay(postDelay); 
}
