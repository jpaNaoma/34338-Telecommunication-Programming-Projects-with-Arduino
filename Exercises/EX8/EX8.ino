// 8a: How is the analog value represented by the MCU?
// analog inputs are 10 bits with the range 0-1023.


// 8b: What is maximum voltage that can be read on A0?
// Normally 5 volts, but on some arduinos it's  3.3 volts


// 8c: Read the voltage on the A0 pin. Does the value seem reasonable?
//yes the value is from 0-1023 depending on how i turn the potentiometer

// 8d: Print out the voltage to the serial monitor with 3 decimals.


// 8e: Use the voltage to control the color of the LED. When applying 0V on the A0 pin the RGB LED should be
// purple and when applying maximum voltage it should be red. When tuning the potentiometer, the RGB LED
// should slowly fade between the different colors.


// Pin definitions
const int Potentiometer = A0;     
const int Red = 13;     
const int Green = 12; 
const int Blue = 11;    

void setup() {
  pinMode(Red, OUTPUT);
  pinMode(Green, OUTPUT);
  pinMode(Blue, OUTPUT);

  Serial.begin(115200);
}

void loop() {
  int Potentiometer_Value = analogRead(Potentiometer);
  Serial.print("Analog value: ");
  Serial.println(Potentiometer_Value);

  // Calculate voltage (3 decimal places)
  float voltage = (Potentiometer_Value*3.3) / 1023.0;

  // Print voltage to serial monitor
  Serial.print("Voltage: ");
  Serial.println(voltage, 3);

  // Map potentiometer value to RGB values
  int redValue = map(Potentiometer_Value, 0, 1023, 128, 255);   
  int blueValue = map(Potentiometer_Value, 0, 1023, 255, 0);    
  int greenValue = map(Potentiometer_Value, 0, 1023, 0, 0);   
  // Set RGB LED colors
  analogWrite(Red, redValue);
  analogWrite(Green, greenValue);
  analogWrite(Blue, blueValue);

  // Small delay for stability
  delay(50);
}
