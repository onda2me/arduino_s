
int ledRed = 13;    // led red 
int ledGreen = 12;  // led green
int ledYellow = 11; // led yellow
  
void setup() {
  
  pinMode(ledRed, OUTPUT);    // define red output
  pinMode(ledGreen, OUTPUT);  // define green output
  pinMode(ledYellow, OUTPUT); // define yellow output
  
}

void loop() {
  
  digitalWrite(ledRed, HIGH);     // red on
  delay(1000); // 1초 기다리기
    
  digitalWrite(ledRed, LOW);      // red off
  
  digitalWrite(ledGreen, HIGH);   // green on
  delay(1000); // 1초 기다리기
  
  digitalWrite(ledGreen, LOW);    // green off
  
  digitalWrite(ledYellow, HIGH);  // yellow on 
  delay(1000); // 1초 기다리기
  
  digitalWrite(ledYellow, LOW);   // yellow off
  
}
