// 7a: What is an RGB value? Why does it use the interval 0-255?

// An RGB value defines a color by combining Red, Green, and Blue intensities (0-255), 
// using 8-bit values per channel to efficiently represent 256 levels for each color.

// 7b: What does the function Serial.parseInt() do ?
//  reads the next integer from the serial input.

// 7c: Parse values from the serial monitor
// • Send a string of three comma separated values from the serial monitor e.g. 200,100,40
// • Read these values as integers (not a string), you can use Serial.parseInt()

// 7d: Use the values the fade the RGB LED.

const int redPin = 13;   
const int greenPin = 12; 
const int bluePin = 11;  

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.begin(115200);
  Serial.println("Send RGB values as: R,G,B");
}

void loop() {
  if (Serial.available() > 0) {
    int redValue = Serial.parseInt();   
    int greenValue = Serial.parseInt(); 
    int blueValue = Serial.parseInt();  

    if (Serial.read() == '\n') {
      Serial.print("R: ");
      Serial.print(redValue);
      Serial.print(", G: ");
      Serial.print(greenValue);
      Serial.print(", B: ");
      Serial.println(blueValue);

      analogWrite(redPin, constrain(redValue, 0, 255));
      analogWrite(greenPin, constrain(greenValue, 0, 255));
      analogWrite(bluePin, constrain(blueValue, 0, 255));
    }
  }
}
