void setup() {
  // put your setup code here, to run once:

    pinMode(A1, INPUT);
    pinMode(12, OUTPUT);

    Serial.begin(9600);
    

}

void loop() {
  // put your main code here, to run repeatedly:

    int a1 = analogRead(A1);

    
    if(a1 < 20) {
  
      digitalWrite(12, HIGH); 
    } else {
      digitalWrite(12, LOW); 
    }

   Serial.println(a1);
   delay(50);

}
