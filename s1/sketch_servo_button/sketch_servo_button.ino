
#include "Servo.h"
Servo servo;

int pinButton = 7;
int pinServo = 8;

void setup() {
  // put your setup code here, to run once:

  // 서보 초기화
  servo.attach(pinServo);
  servo.write(0);  
  servo.detach();

  // 택트 스위치 설정
  pinMode(pinButton, INPUT_PULLUP);

  // 시리얼모니터 설정
  Serial.begin(9600);
}

void loop() {

  // 버튼을 눌렸는지 확인한다. (눌렀을때 : false, 안눌렀을때 : true)
  boolean button = digitalRead(pinButton);

  if(button == false) {

    servo.attach(pinServo);

    // 서보모터 회전시키기 ( 90 -> 180 -> 90 -> 0)
    servo.write(90);    
    delay(1000);
    
    servo.write(180);   
    delay(1000);
    
    servo.write(90);   
    delay(1000);   
    
    servo.write(0);    

    servo.detach();
  }

}
