#include <Wire.h>  // Wire 헤더파일 호출
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤더파일 호출

LiquidCrystal_I2C lcd(0x3f, 16, 2); // LCD의 address 주소 및 크기 입력

int pinTrig = 3;
int pinEcho = 4;
int pinButton = 8;
int jumpPoint = 0;

int pullBtn = 1;
int speedLevel = 4;
String patternIcon ="O";
String patternBump = "B ";
String patternCrush = "XX";

int duration = 0;
int distance = 0;

boolean isGameing = false;
  
void setup() {  

  Serial.begin(9600);

  lcd.init();  // LCD 초기화

  lcd.backlight();  // LCD 백라이트 함수
  
  // 버튼 설정
  pinMode(pinButton, INPUT_PULLUP);

  // 초음파 센서 Trig, Echo Pin 설정
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  
  startGame();
}


void loop() { 

  // 게임 시작 (게임중이 아니고, 시작버튼 누르면)
  if( isGameing == false && digitalRead(pinButton) == false) {          
    startGame();
  }

  // 다음 단계 시작
  delay(1000);
 
}

//---------------------------------------------------------
// 게임 시작
//---------------------------------------------------------  
void startGame() {

  isGameing = true;
    
  lcd.setCursor(0, 0);
  lcd.print("Press start");
  delay(1000);

  lcd.clear();  
  playGame();

}

// playGame
void playGame() {
    
  for(int i=15; i>0; i--) {

    // 거리가 가까운지 체크. (가깝다 : 0, 멀다 : 1)
    pullBtn = isFar();
   
    //아이콘
    printIcon(pullBtn);

    //폭탄
    printBump(i, pullBtn);

    //점수
    printJumpPoint();
          
    delay(speedLevel*100);
  }

  speedLevel = random(2, 4);
}


void printIcon(int isPull) {
    
    // 안눌렀을때 == 당겨있을때 == 1
    if( isPull == 1) {
      
      lcd.setCursor(1, 0);
      lcd.print(" ");
      lcd.setCursor(1, 1);
      lcd.print(patternIcon);    
      
    // 눌러있을때 == 안당겨있을때 == 0
    } else {
      
      lcd.setCursor(1, 0);
      lcd.print(patternIcon);
      lcd.setCursor(1, 1);
      lcd.print(" ");  
      
    }


}

void printBump(int i, int isPull) {

   if(i == 1 ) {
    
      // 충돌 : 게임 끝
      if(isPull == 1) {

        isGameing = false;
                
        lcd.setCursor(1,1);
        lcd.print(patternCrush);

        lcd.setCursor(1,0);
        lcd.print("Press start");

      //점수 추가
      } else {
        jumpPoint++;

        lcd.setCursor(1, 1);
        lcd.print(patternBump);     

        delay(500);   
        playGame();            
      }    
   } else {
    
    lcd.setCursor(i, 1);
    lcd.print(patternBump);      
   }
}

void printJumpPoint() {
  lcd.setCursor(13,0); 
  lcd.print("P:");  
  lcd.print(jumpPoint);
}

// 초음파 센서로 거리 측정하여 결과 저장하기
boolean isFar() {
  
  digitalWrite(pinTrig, LOW);
  delayMicroseconds(10);
  digitalWrite(pinTrig, HIGH);

  duration = pulseIn(pinEcho, HIGH);
  distance = duration / 2 / 29.1;


  // 거리가 10cm 보다 가까운지 체크
  if(distance < 10) {    
    return false;
  } else {
    return true;
  }
  
    

}
