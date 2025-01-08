
// //2a------------------------------------------------------
// // 42 % 5 
// // dette giver en rest på 2
// // dvs at der divideres med 5, og det overskydende er 2


// //2b------------------------------------------------------
// // Definer LED-pins
// const int greenLED = 4;
// const int yellowLED = 3;
// const int redLED = 2;

// void setup() {
//   Serial.begin(115200); // Start serial kommunikation
//   // Definer pins som OUTPUT
//   pinMode(greenLED, OUTPUT);
//   pinMode(yellowLED, OUTPUT);
//   pinMode(redLED, OUTPUT);
// }

// void loop() {
//   Serial.println("KØR!");
//   digitalWrite(greenLED, HIGH);
//   delay(5000);
//   digitalWrite(greenLED, LOW);

//   Serial.println("Ready?");
//   digitalWrite(yellowLED, HIGH);
//   delay(2000); 
//   digitalWrite(yellowLED, LOW);


//   Serial.println("STOP!");
//   digitalWrite(redLED, HIGH);
//   delay(5000); 
//   digitalWrite(redLED, LOW);

//    Serial.println("Ready?");
//   digitalWrite(yellowLED, HIGH);
//   delay(2000); 
//   digitalWrite(yellowLED, LOW);
// }

//2c-----------------------------------------------------------------

const int LED1 = 4;
const int LED2 = 3;
const int LED3 = 2;

void setup() {
  Serial.begin(115200); 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
}

void loop() {
  Serial.println("0");
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);     ¨
   digitalWrite(LED3, LOW);
delay(1000);

  Serial.println("1");
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, LOW);     
   digitalWrite(LED3, HIGH);
delay(1000);

  Serial.println("2");
   digitalWrite(LED1, LOW);
   digitalWrite(LED2, HIGH);     
   digitalWrite(LED3, LOW);
delay(1000);

 Serial.println("3");
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, LOW);     
   digitalWrite(LED3, LOW);
delay(1000);

 Serial.println("4");
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, LOW);     
   digitalWrite(LED3, HIGH);
delay(1000);

 Serial.println("5");
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, LOW);     
   digitalWrite(LED3, HIGH);
delay(1000);

 Serial.println("6");
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, HIGH);     
   digitalWrite(LED3, LOW);
delay(1000);

 Serial.println("7");
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, HIGH);     
   digitalWrite(LED3, HIGH);
delay(1000);
}

//2d------------------------
// % kunne bruges når en counter skal nulstilles 
