#include <Wire.h>  // Wire 헤더파일 호출
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤다파일 호출

LiquidCrystal_I2C lcd(0x3f, 16, 2); // LCD의 address 주소 및 크기 입력


void setup() {  

  lcd.init();  // LCD 초기화

  lcd.backlight();  // LCD 백라이트 함수

  lcd.print("Hello, world!");  // 원하는 문구 입력

}

void loop() { 

}
