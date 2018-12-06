#include <Wire.h>  // Wire 헤더파일 호출
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤더파일 호출

LiquidCrystal_I2C lcd(0x3f, 16, 2); // LCD의 address 주소 및 크기 입력


void setup() {  

  lcd.init();  // LCD 초기화

  lcd.backlight();  // LCD 백라이트 함수

  lcd.print("Hello, World!!");  // 원하는 문구 입력
  delay(1000);

  //---------------------------------------------------------
  // 아래부터는 LCD Function Test
  //---------------------------------------------------------
  lcd.clear();
  
  lcd.blink();
  delay(1000);
  
  lcd.print("Good Bye~");
  delay(1000);

  lcd.clear();

  lcd.print("See You Later");
  delay(1000);

  lcd.blink();
  delay(2000);


  

}

void loop() { 

}
