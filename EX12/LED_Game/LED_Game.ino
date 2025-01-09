#include <LiquidCrystal.h>

// Pin assignments for LEDs and Button
const int ledPins[] = {2, 3, 4, 5, 6}; // 5 LEDs
const int buttonPin = 13; // Button
int buttonState = 0; // Current state of the button
int lastButtonState = 0; // Previous button state for debouncing
int hitCount = 0; // Number of correct hits
int missCount = 0; // Number of misses
int speed = 500; // Flashing speed (milliseconds)

// LCD setup
const int rs = 12, en = 11, d4 = 10, d5 = 9, d6 = 8, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize LED pins
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT);

  // Initialize LCD
  lcd.begin(16, 2);
  lcd.print("Catch the LED!");
  delay(2000); // Display the start message
  lcd.clear();
}

void loop() {
  static int count = 0;
  static int currentLED = 0;
  static unsigned long lastFlashTime = 0;
  
  // Handle button debouncing
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Button pressed
    checkHit(currentLED);
    lastButtonState = buttonState;
  }
  if (buttonState == LOW) {
    lastButtonState = buttonState;
  }

  // Flash LEDs in sequence
  if (millis() - lastFlashTime > speed) {
    lastFlashTime = millis();

    // Turn off all LEDs
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPins[i], LOW);
    }

    // Turn on the current LED
    digitalWrite(ledPins[currentLED], HIGH);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("LED: ");
    lcd.print(currentLED + 1); // Display LED number (1-5)

    // Update the current LED for the next flash
    currentLED = (currentLED + 1) % 5;
  }

  // Check for win or loss conditions
  if (hitCount >= 10) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You Win!");
    delay(3000); // Wait 3 seconds before restarting the game
    resetGame();
  } else if (missCount >= 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miss! Try again.");
    delay(1000); // Wait 1 second before restarting the game
    resetGame();
  }

  count++;
  delay(10); // Small delay for debouncing and game logic timing
}

/**
 * Check if the button was pressed at the correct time
 * @param led The index of the LED that was lit
 */
void checkHit(int led) {
  if (led == 2) { // Middle LED (LED 3)
    hitCount++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hit: ");
    lcd.print(hitCount);
  } else {
    missCount++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miss: ");
    lcd.print(missCount);
    delay(1000); // Turn off LEDs for 1 second when the player misses
    resetGame();
  }
}

/**
 * Reset the game counters and flashing speed
 */
void resetGame() {
  hitCount = 0;
  missCount = 0;
  speed = 1000; // Reset to initial flashing speed
  delay(1000); // Wait 1 second before restarting the game
}

/**
 * Doxygen Documentation for the main game logic
 *
 * @brief This program implements the "Catch the LED" game using Arduino and an LCD screen.
 * The player must press a button when the middle LED lights up. The game gets progressively harder
 * as the player hits more LEDs. When the player reaches 10 hits, they win the game.
 *
 * @param led The current LED that is lit up.
 * @param buttonPin The pin to which the button is connected.
 * @param ledPins Array holding the pin numbers for the LEDs.
 * @param lcd LCD object for displaying the game state.
 */

