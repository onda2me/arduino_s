void setup() {
  // put your setup code here, to run once:

  pinMode(11, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // 점점 밝아지기
  for(int i=0; i<256; i++) {
    analogWrite(11, i); 
    delay(10);
  }

  // 점점 어두워지기
  for(int i=255; i>=0; i--) {
    analogWrite(11, i); 
    delay(10);
  }



}
