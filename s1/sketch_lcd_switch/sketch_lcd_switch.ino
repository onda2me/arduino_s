#include <Wire.h>  // Wire 헤더파일 호출
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤더파일 호출

LiquidCrystal_I2C lcd(0x3f, 16, 2); // LCD의 address 주소 및 크기 입력

int pinButton = 8;
int jumpPoint = 0;

boolean button = true;
  
void setup() {  

  lcd.init();  // LCD 초기화

  lcd.backlight();  // LCD 백라이트 함수

  // 버튼 설정
  pinMode(pinButton, INPUT_PULLUP);
 
  // 게임 시작
  lcd.setCursor(0, 0);
  lcd.print("Game Start..!!");
  delay(1000);

  //---------------------------------------------------------
  // 아래부터는 LCD Function 
  //---------------------------------------------------------
  lcd.clear();

  for(int i=15; i>0; i--) {

    // 버튼을 눌렸는지 확인한다. (눌렀을때 : false, 안눌렀을때 : true)
    // 눌렀을 때 점프동작
    if(digitalRead(pinButton) == false) {

      //점수 추가
      addJumpPoint();

      //점프
      printJumpIcon();

      //폭탄
      printBump(i);
      
    // 안눌렀을 때 제자리
    } else {

      // 걷기 동작
      printWalkIcon();
      
     if(i == 1) {
      lcd.setCursor(1,1);
      lcd.print("XX");
     } else {
      lcd.setCursor(i,1);
      lcd.print("B ");
     }
    }
    
    delay(500);
  }
}

void loop() { 

}

void addJumpPoint() {
  jumpPoint++;
  lcd.setCursor(15,0); 
  lcd.print(jumpPoint);
}

void printJumpIcon() {
      lcd.setCursor(1, 0);
      lcd.print("O");
      lcd.setCursor(1, 1);
      lcd.print(" ");         
}

void printWalkIcon() {
      lcd.setCursor(1, 0);
      lcd.print(" ");
      lcd.setCursor(1, 1);
      lcd.print("O");    
}

void printBump(int i) {
      lcd.setCursor(i,1);
      lcd.print("B ");
}
