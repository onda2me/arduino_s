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

int pinBusor = 13;

int pinLedDo = 2;
int pinLedRe = 3;
int pinLedMi = 4;
int pinLedPa = 5;
int pinLedSol = 6;
int pinLedLa = 7;


int nTone[] = {262, 294, 330, 349, 392, 440, 494, 523 };  
int nMusic[] = {0, 2, 4, 0, 2, 4, 5, 5, 5, 4, 4, 4, 3, 3, 3, 2, 2, 2, 1, 1, 1, 0, 0, 0}; 
int nPin[] = {2, 3, 4, 5, 6, 7 }; 
int sizeMusic = sizeof(nMusic) / sizeof(int);

void setup() {
  // put your setup code here, to run once:

    pinMode(pinLedDo, OUTPUT);
    pinMode(pinLedRe, OUTPUT);
    pinMode(pinLedMi, OUTPUT);
    pinMode(pinLedPa, OUTPUT);
    pinMode(pinLedSol, OUTPUT);
    pinMode(pinLedLa, OUTPUT);

    
    for (int i = 0; i< sizeMusic; i++) {

      digitalWrite(nPin[nMusic[i]], HIGH);
      tone(pinBusor, nTone[nMusic[i]]);
      delay(300);      
      digitalWrite(nPin[nMusic[i]], LOW);
    }
  
    noTone(pinBusor);
    
}

void loop() {
  // put your main code here, to run repeatedly:

 }
