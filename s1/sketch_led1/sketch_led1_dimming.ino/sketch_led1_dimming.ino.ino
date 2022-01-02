 void setup() {
  pinMode(6, OUTPUT);  
  
  // 시리얼모니터 설정
  Serial.begin(9600);
}

void loop() {

  for(int i=0; i<255; i++) {
    analogWrite(6, i); // LED 밝아지기    
    delay(5);
  }
  
  for(int i=255; i>0; i--) {
    analogWrite(6, i); // LED 어두워지기     
    delay(5);
  }  
}
