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


void setup() {
  // put your setup code here, to run once:

  pinMode(12, OUTPUT);

  digitalWrite(12, HIGH);

  tone(9, 262);
  delay(100);

  tone(9, 294);
  delay(100);

  tone(9, 330);
  delay(100);

  tone(9, 349);
  delay(100);
  
  tone(9, 523);
  delay(100);
  
  noTone(9);
  digitalWrite(12, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

}
