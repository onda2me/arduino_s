
#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:

  dht.begin();
  Serial.begin(9600);
}

float h = 0;
float t = 0;

void loop() {
  // put your main code here, to run repeatedly:

  h = dht.readHumidity();     // 습도
  t = dht.readTemperature();  // 온도

  Serial.print("\n\nh ::: ");
  Serial.println(h);
  Serial.print("t ::: ");
  Serial.println(t);

  delay(1000);

}
