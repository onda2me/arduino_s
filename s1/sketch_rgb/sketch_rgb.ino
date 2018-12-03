
  int ledRed = 9;
  int ledGreen = 10;
  int ledBlue = 11;
  

void setup() {

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  
}

void loop() {

  // red on
  digitalWrite(ledRed, HIGH); 
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  delay(1000); // 1초 기다리기

 // green on
  digitalWrite(ledRed, LOW); 
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  delay(1000); // 1초 기다리기

  // blue on
  digitalWrite(ledRed, LOW); 
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, HIGH);
  delay(1000); // 1초 기다리기

 // red + green on = yellow
  digitalWrite(ledRed, HIGH); 
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, LOW);
  delay(1000); // 1초 기다리기

  // red + green + blue on = white
  digitalWrite(ledRed, HIGH); 
  digitalWrite(ledGreen, HIGH);
  digitalWrite(ledBlue, HIGH);
  delay(1000); // 1초 기다리기

  
  // red + green + blue off = 꺼짐
  digitalWrite(ledRed, LOW); 
  digitalWrite(ledGreen, LOW);
  digitalWrite(ledBlue, LOW);
  delay(1000); // 1초 기다리기

}
