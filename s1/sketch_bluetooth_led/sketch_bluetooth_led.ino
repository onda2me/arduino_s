#include <SoftwareSerial.h>

SoftwareSerial btSerial(0, 1); // RX, TX
int pinLed = 13;

void setup() {

  pinMode(pinLed, OUTPUT); 
  btSerial.begin(9600);
  
}

void loop() {

  if(btSerial.available()) {
    char c = btSerial.read();

    switch(c) {

      case '1':
        digitalWrite(pinLed, HIGH);
        break;
      case '0':
        digitalWrite(pinLed, LOW);
        break;
    }    
  }

  delay(500);
}
