#define sensorPin A0
#include <LiquidCrystal.h>

// Initialize the LCD pins
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(115200); 

  // Set up the LCD's number of columns and rows:
  lcd.begin(16, 2);

  // Print a startup message to the LCD:
  lcd.print("Reading Temp...");
  delay(2000); // Display the startup message for 2 seconds
  lcd.clear(); // Clear the screen
}

void loop() {
  int reading = analogRead(sensorPin);

  float voltage = reading * (5.0 / 1023.0);

  // Convert voltage to temperature in Celsius (LM35 outputs 10mV/°C)
  float temperatureC = voltage * 100;

  // Print the temperature in Celsius
  Serial.print("Temp value: ");
  Serial.println(temperatureC);
  Serial.print("\xC2\xB0"); // shows degree symbol
  Serial.println("C ");
  
 // Display temperature on the LCD
  lcd.clear();
  lcd.setCursor(0, 0); // Set cursor to the first line
  lcd.print("Temp: ");
  lcd.print(temperatureC);
  lcd.print(" C");

  delay(1000);
}






