//Execise 6
//6.a A char is a character. It is a data type used in programming representing a
// single char.
//6.b The stored value in mychar is 68 or D in ASCII table. First val value is, '4' is 52 and '0' 
//is 48. So val = 52-48 = 4. Mychar is val + A -1 =  4 + 65 -1 = 68.


int redLED1 = 12;
int redLED2 = 11;
int redLED3 = 10;
int redLED4 = 9;
int redLED5 = 8;

char incomingChar;

char mychar = '4';
int val = mychar-'0';

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(redLED1, OUTPUT); // LED for a
pinMode(redLED2, OUTPUT); // LEd for b
pinMode(redLED3, OUTPUT); // LED for c
pinMode(redLED4, OUTPUT); // LED for d
pinMode(redLED5, OUTPUT); // LED for e
Serial.print("hej");

mychar = (char)(val+'A'-1);

}

void loop() {
  // put your main code here, to run repeatedly:

// Check if data is available in the serial buffer
  if (Serial.available() > 0) {

    incomingChar = Serial.read(); // Read the incoming character
    Serial.print("Received: ");
    Serial.println(incomingChar);

    // Turn off all LEDs first
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    digitalWrite(8, LOW);

    // Light up the appropriate LED based on the character received
    switch (incomingChar) {
      case 'a':
        digitalWrite(12, HIGH);
        break;
      case 'b':
        digitalWrite(11, HIGH);
        break;
      case 'c':
        digitalWrite(10, HIGH);
        break;
      case 'd':
        digitalWrite(9, HIGH);
        break;
      case 'e':
        digitalWrite(8, HIGH);
        break;
      default:
        Serial.println("Invalid character. Send a, b, c, d, or e.");
    }
  }

}
