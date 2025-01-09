#define sensorPin A0
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const int RED = 4;
const int Yellow = 3;
const int Green = 2;

// Variables to store the current LED state
int currentState = -1; // -1 indicates no state set

void setup() {
  Serial.begin(115200); 
  pinMode(RED, OUTPUT);
  pinMode(Yellow, OUTPUT);
  pinMode(Green, OUTPUT);

 
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
  Serial.print("\xC2\xB0"); 
  Serial.println("C ");
  
  // Display warning if temperature is too high
  if (temperatureC > 30) {
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("WARNING:");
    lcd.setCursor(0, 1); 
    lcd.print("Temp too high!");
  } else {

    // Display temperature on the LCD
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Temp: ");
    lcd.print(temperatureC);
    lcd.print(" C");
  }

  // Update LEDs only if the state changes
  int newState;
  if (temperatureC > 27) { // Hot
    newState = 0;
  } else if (temperatureC > 26) { // Slightly hot
    newState = 1;
  } else { // Normal
    newState = 2;
  }

  // Check if the state has changed
  if (newState != currentState) {
    currentState = newState; // Update the state

    if (currentState == 0) { // Hot
      digitalWrite(RED, HIGH);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green, LOW);
    } else if (currentState == 1) { // Slightly hot
      digitalWrite(RED, LOW);
      digitalWrite(Yellow, HIGH);
      digitalWrite(Green, LOW);
    } else { // Normal
      digitalWrite(RED, LOW);
      digitalWrite(Yellow, LOW);
      digitalWrite(Green, HIGH);
    }
  }

  delay(1000);
}
