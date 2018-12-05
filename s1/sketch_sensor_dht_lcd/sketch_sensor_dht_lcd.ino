#include <Wire.h>  // Wire 헤더파일 호출
#include <LiquidCrystal_I2C.h>  // LiquidCrystal_I2C 헤더파일 호출
#include <DHT.h>


#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x3f, 16, 2); // LCD의 address 주소 및 크기 입력


void setup() {  

  lcd.init();  // LCD 초기화

  lcd.backlight();  // LCD 백라이트 함수

  lcd.print("Temperature .... ");  // 원하는 문구 입력
  delay(1000);
  
  dht.begin();
  Serial.begin(9600);
  
}

float h = 0;
float t = 0;

void loop() { 

  h = dht.readHumidity();     // 습도
  t = dht.readTemperature();  // 온도

  lcd.clear();
  lcd.print("Hum : ");
  lcd.println(h);
  
  delay(500);
  
  lcd.setCursor(0, 1);
  lcd.print("Temper : ");
  lcd.println(t);
  
  Serial.print("\n\nh ::: ");
  Serial.println(h);
  Serial.print("t ::: ");
  Serial.println(t);

  delay(1000);
  
}
