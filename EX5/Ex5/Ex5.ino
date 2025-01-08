int incomingByte = 0;

// 5a: Read the following code, try to explain what it does. See Serial.available() and Serial.read() for more info.

// This part opens the serial monitor and read the input and converts it to ascii.
// 5b: Implement the code in your own IDE.
void setup() {

  Serial.begin(115200);

}


void loop() {

  if (Serial.available() > 0) {
  incomingByte = Serial.read();
  Serial.print("I received: "); 
  // Serial.println(incomingByte, DEC);
  Serial.println((char)incomingByte);
}

}


// 5c: Open the serial monitor (ctrl+shift+m), and set it to ”no line ending”. Send some data using the top
// line of the serial monitor.
// when ”no line ending” is on i get the ascii value for what i input. 

// 5d: Why are you not receiving what you wrote? (e.g. G becomes 71)
//because it is the ascii value converted to decimal

// 5e: What happens if the serial monitor sends a line ending?
// and when not, i get a value of 10, which mean new line

// 5f: Try changing the line Serial.print(incomingByte, DEC) 
// to Serial.print((char)incomingByte). What happens?
// Why?
// Now the actual input is printed.
