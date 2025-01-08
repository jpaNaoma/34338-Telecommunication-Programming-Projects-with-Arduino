//3a-----------------------------------
// Det er en intern pull-up resistor, og derfor er INPUT_PULLUP høj fra starten af

//3b---------------------------------------------
// operatoren ! betyder at det er det modsatte. hvis !true = false og omvendt


//3c1---------------------------------------------------------------------------
// const int LED = 2;
// const int butn = 7;
// int buttonState = 0;

// void setup() {
//   Serial.begin(115200); 
//   pinMode(LED, OUTPUT);
//   pinMode(butn, INPUT_PULLUP);  
// }

// void loop() {
//   buttonState = digitalRead(butn);

//   if (buttonState == LOW) {
//     digitalWrite(LED, HIGH);
//   } else {
//     digitalWrite(LED, LOW);
//   }
// }

// 3c2-----------------------------------------------------------------------------

const int LED = 2;
const int butn = 7;
int butnState = 0;
int lastbutnState = 0;  
bool LEDState = false;    

void setup() {
  Serial.begin(115200); 
  pinMode(LED, OUTPUT);
  pinMode(butn, INPUT_PULLUP);  
}

void loop() {
  butnState = digitalRead(butn); 

  if (butnState == LOW && lastbutnState == HIGH) {
    LEDState = !LEDState; 
    digitalWrite(LED, LEDState ? HIGH : LOW);  
    delay(200);  
  }

  lastbutnState = butnState;
}


//3D-----------------------------------------------
// Der checkes om knappen er trykket konstant. 
//Derfor kan vores state også skifter flere gange
// for at undgå dette, bruges en debounce på 200 ms. derved kan der kun ske en state
//change hver 200 ms.