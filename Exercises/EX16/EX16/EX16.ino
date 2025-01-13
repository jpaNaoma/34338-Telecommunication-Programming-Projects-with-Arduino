#include <dummy.h>

/* 

16b: What is a server?
A server is a system or device that provides services or resources, 
like hosting websites or 
managing data, to other devices (clients) over a network.


16a: What is a GET request? And how is it different to a POST request

GET request: Retrieves data from a server, typically for 
reading or displaying (e.g., loading a webpage).

POST request: Sends data to the server, usually to submit 
or update information (e.g., submitting a form).


16c: Follow the guidelines given in the document
 ”Programming with Arduino - Webserver 2018”


*/

#include <WiFi.h>              // Include WiFi library for ESP32
#include <WebServer.h>         // Include WebServer library for ESP32
#include <ESPmDNS.h>           // Include mDNS library for ESP32

WebServer server(80);          // Create an instance of the server on port 80

const int led = 2;             // LED pin (GPIO2 on ESP32, onboard LED)

void handleRoot();  
void handleLED();  
void handleNotFound();

void setup() {
  Serial.begin(115200);
  delay(10);

  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);     // Initialize LED off
  
  // Connect to WiFi network
  Serial.println();
  WiFi.begin("Jarls Galaxy", "jarlvep26"); // Replace with your WiFi credentials
  
  Serial.println("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("iot")) {     // Start mDNS responder for esp32.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  // Define server routes
  server.on("/", HTTP_GET, handleRoot);
  server.on("/LED", HTTP_POST, handleLED);
  server.onNotFound(handleNotFound);
    
  // Start the server
  server.begin();
  Serial.println("Server started");
}

void loop() {
  server.handleClient(); // Handle incoming client requests
}

void handleRoot() {  // Send a web page with a button to toggle the LED
  server.send(200, "text/html", "<html><title>Internet of Things - Demonstration</title><meta charset=\"utf-8\" /> \
      <head><body><h1>Welcome to this WebServer</h1> \
      <p>Internet of Things (IoT) refers to connecting everyday objects to the internet for new value and solutions.</p> \
      <p>This demonstration uses an ESP32 microcontroller to control a digital output (LED), which could be applied to lamps, fans, or heaters.</p> \
      <p>Click the button below to toggle the LED on GPIO2.</p> \
      <form action=\"/LED\" method=\"POST\"><input type=\"submit\" value=\"Toggle LED State\" style=\"width:500px; height:100px; font-size:24px\"></form> \
      <p>With an ESP32, you can create many fun and useful projects!</p> \
      <p>Learn more about the program: <a href=\"www.dtu.dk/net\">Netværksteknologi og it</a></p> \
      </body></html>");
}

void handleLED() {  // Handle POST requests to /LED
  digitalWrite(led, !digitalRead(led)); // Toggle the LED state
  server.sendHeader("Location", "/");  // Redirect back to the root
  server.send(303);                    // Send 303 HTTP status
}

void handleNotFound() { // Handle requests to undefined routes
  server.send(404, "text/plain", "404: Not found");
}
