/*
 * 
 * 도 262
 * 레 294
 * 미 330
 * 파 349
 * 솔 392
 * 라 440
 * 시 494
 * 도 523
 */

int pinBusor = 9;

// 도,레,미 . . . 도 의 음계를 배열로 지정한다.
int nTone[] = {262, 294, 330, 349, 392, 440, 494, 523 };  

void setup() {
  // put your setup code here, to run once:

  // 도~도 까지 음을 출력한다.
  for (int i = 0; i< 8; i++) {
    tone(pinBusor, nTone[i]);
    delay(500);
  }

  noTone(pinBusor);
  delay(500);

}

void loop() {
  // put your main code here, to run repeatedly:

 }
