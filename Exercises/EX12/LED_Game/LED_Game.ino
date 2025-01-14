/**
 * @file LED_Game.ino
 * @author Jarl Pallesen
 * @brief 
 * @version 0.1
 * @date 2025-01-10
 * 
 * @copyright Copyright (c) 2025
 * @mainpage Exercise 12
 * 
 * @section Intro
 * 
 */



#include <Wire.h>
#include <LiquidCrystal_I2C.h>

/**
 * @brief LCD object to control the display
 */

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin assignments
const int ledPins[] = {2, 3, 4, 5, 6}; /**< Pins for the LEDs */
const int buttonPin = 7; /**< Pin for the button */
int buttonState = HIGH; /**< Current button state */
int lastButtonState = HIGH; /**< Last button state for debouncing */
unsigned long lastDebounceTime = 0; /**< Last debounce time */
const unsigned long debounceDelay = 50; /**< Debounce delay in ms */
int hitCount = 0; /**< Counter for hits */
int missCount = 0; /**< Counter for misses */
int speed = 500; /**< Speed of the LED flashing */

/**
 * @brief Initializes the game setup
 * Initializes the LED pins, button pin, and LCD screen.
 */
void setup() {
  // Initialize LED pins
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.print("Catch the LED!");
  delay(2000); 
  lcd.clear();
}

/**
 *  @brief Main game loop that flashes LEDs and checks for button presses.
 * 
 */
 void loop() {
  static int currentLED = 0; /**< Tracks the currently lit LED */
  static unsigned long lastFlashTime = 0;

  // Read button state with debounce
  int reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading == LOW && buttonState == HIGH) {
      checkHit(currentLED);
    }
    buttonState = reading;
  }
  lastButtonState = reading;

  // Flash LEDs
  if (hitCount < 8) { // Sequential LED flashing before hitCount reaches 8
    if (millis() - lastFlashTime > speed) {
      lastFlashTime = millis();

      // Turn off all LEDs
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledPins[i], LOW);
      }

      // Turn on the current LED
      digitalWrite(ledPins[currentLED], HIGH);

      // Move to the next LED
      currentLED = (currentLED + 1) % 5;
    }
  } else { // Random LED flashing after hitCount reaches 8
    if (millis() - lastFlashTime > speed) {
      lastFlashTime = millis();

      // Turn off all LEDs
      for (int i = 0; i < 5; i++) {
        digitalWrite(ledPins[i], LOW);
      }

      // Turn on a random LED
      int randomLED = random(0, 5); // Random LED index (0-4)
      digitalWrite(ledPins[randomLED], HIGH);
      currentLED = randomLED; // Update current LED to match the randomly chosen LED
    }
  }

  // Check win or loss conditions
  if (hitCount >= 10) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("You Win!");
    delay(3000); 
    resetGame();
  } else if (missCount >= 3) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Game Over!");
    delay(3000); 
    resetGame();
  }
}

/**
 * @brief Checks if the player hit the correct LED (pin 3).
 * @param led The index of the LED that was lit (0-based)
 */
void checkHit(int led) {
  if (led == 3) {  // Only register a hit when pin 3 is lit
    hitCount++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Hit: ");
    lcd.print(hitCount);

    // Celebratory LED flashing 
    for (int i = 0; i < 3; i++) { 
      for (int j = 0; j < 5; j++) {
        digitalWrite(ledPins[j], HIGH); 
      }
      delay(100); 
      for (int j = 0; j < 5; j++) {
        digitalWrite(ledPins[j], LOW); 
      }
      delay(100); 
    }

    speed = max(100, speed - 70); // Increase difficulty by speeding up
  } else {
    missCount++;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Miss: ");
    lcd.print(missCount);
    delay(1000); 
  }
}

/**
 * @brief Resets the game counters and LED flashing speed
 */
void resetGame() {
  hitCount = 0;
  missCount = 0;
  speed = 500; // Reset to initial flashing speed
  delay(1000); // Pause before restarting
}
