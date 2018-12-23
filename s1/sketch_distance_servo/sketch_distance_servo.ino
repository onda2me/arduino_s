
#include "Servo.h"
Servo servo;

int pinTrig = 3;
int pinEcho = 4;
int pinServo = 8;

int duration = 0;
int distance = 0;

void setup() {
  // put your setup code here, to run once:

  // 서보 초기화
  servo.attach(pinServo);
  servo.write(0);  
  servo.detach();

  // 초음파 센서 Trig, Echo Pin 설정
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);

  // 시리얼모니터 설정
  Serial.begin(9600);
 
}

void loop() {
 
  // 거리 측정하기
  measure();

  // 거리가 10cm 보다 가까우면 모터 회전하기
  if(distance < 10) {    
    rotaion();
  }

  delay(500);  
}

// 초음파 센서로 거리 측정하기
void measure() {
  
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(pinTrig, HIGH);

  duration = pulseIn(pinEcho, HIGH);
  distance = duration / 2 / 29.1;
}

// 서보모터 회전하기
void rotaion() {

  servo.attach(pinServo);

  //회전
  servo.write(180);
  Serial.print("서보회전각1 : ");
  Serial.println(servo.read());   
  delay(2000);

  //복귀
  servo.write(0);
  Serial.print("서보회전각2 : ");
  Serial.println(servo.read());  
  delay(500);
      
  servo.detach();
}
