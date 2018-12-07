
#include "Servo.h"
Servo servo;

int pinServo = 8;

void setup() {
  // put your setup code here, to run once:

  // 서보 초기화
  servo.attach(pinServo);
  servo.write(0);  
  servo.detach();

  // 시리얼모니터 설정
  Serial.begin(9600);
}

void loop() {

  servo.attach(pinServo);

  //시작
  Serial.print("서보회전각1 : ");
  Serial.println(servo.read());  
  
  // 서보모터 회전시키기 ( 90 -> 180 -> 0)
  servo.write(90);
  Serial.print("서보회전각2 : ");
  Serial.println(servo.read());   
  delay(1000);
  
  servo.write(180);
  Serial.print("서보회전각3 : ");
  Serial.println(servo.read());   
  delay(1000);

  //0으로 회전각
  servo.write(0);
  Serial.print("서보회전각4 : ");
  Serial.println(servo.read());  
  delay(1000);
      
  servo.detach();

}
