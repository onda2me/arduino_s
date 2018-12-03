void setup() {
  // put your setup code here, to run once:

  // 버튼 입력
  pinMode(7, INPUT_PULLUP);
  
  // LED 출력
  pinMode(13, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // 버튼을 눌렸는지 확인한다. (눌렀을때 : false, 안눌렀을때 : true)
  boolean button = digitalRead(7);

  // 버튼을 안눌렀을때 LED를 끈다
  if(button == true) {
    digitalWrite(13, LOW);

  // 버튼을 눌렀을때 LED를 켠다
  } else {
    digitalWrite(13, HIGH);
  }

}
