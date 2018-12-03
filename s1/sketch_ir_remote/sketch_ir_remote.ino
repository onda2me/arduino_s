#include <IRremote.h>

int RECV_PIN = 11;

IRrecv ir(RECV_PIN);

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  ir.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");

}

void loop() {
  // put your main code here, to run repeatedly:

  decode_results res;

    
  if(ir.decode(&res)) {

    Serial.println(res.value, HEX);

   Serial.print("res.value -->> ");
   Serial.println(res.value);
    delay(1000);

    ir.resume(); // Receive the next value
    
  } else {
     Serial.println("data is none..............");
      delay(1000);
  }
}
