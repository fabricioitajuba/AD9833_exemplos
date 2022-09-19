/*
 * Vcc - 5V
 * DGND - GND
 * FSYNC - 10
 * SDATA - 11
 * SCLK - 13
 */

#include <AD9833.h>     // Include the library
 
#define FNC_PIN 10       // Can be any digital IO pin
 
AD9833 gen(FNC_PIN);       // Defaults to 25MHz internal reference frequency

float f;

void setup() {

  Serial.begin(9600);

  gen.Begin();              
  gen.EnableOutput(true);

  Serial.print(F("\n- Teste do DDS AD9833"));
  Serial.print(F("\nEntre com uma frequência [Hz]:"));
}
 
void loop() {  
  if(Serial.available()){  
    f = Serial.parseFloat();
    Serial.println(f);
    gen.ApplySignal(SINE_WAVE,REG0,f);
    Serial.print(F("\nEntre com uma frequência [Hz]:"));
  }  
}
