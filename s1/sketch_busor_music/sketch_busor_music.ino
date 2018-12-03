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

int pinButton = 8;
int pinBusor = 9;
int pinLed = 12;

int nTone[] = {262, 294, 330, 349, 392, 440, 494, 523 };  
int nMusic[] = {4, 4, 5, 5, 4, 4, 2, 2, 4, 4, 2, 2, 1, 1, 1, 4, 4, 5, 5, 4, 4, 2, 2, 4, 2, 1, 2, 0, 0, 0}; 
int sizeMusic = sizeof(nMusic) / sizeof(int);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(pinButton)) {

    pinMode(pinLed, OUTPUT);
    digitalWrite(pinLed, HIGH);

    for (int i = 0; i< sizeMusic; i++) {
      tone(pinBusor, nTone[nMusic[i]]);
      Serial.print("[");
      Serial.print(i);
      Serial.print(" ] = ");
      Serial.print(nMusic[i] );
      Serial.print(" -> ");
      Serial.println(nTone[nMusic[i]]);
      delay(300);
    }
  
    noTone(pinBusor);
    digitalWrite(pinLed, LOW);
  }
 }
