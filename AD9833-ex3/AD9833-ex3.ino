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

void configura_frequencia(){

  Serial.print(F("\nEntre com a frequência [Hz]:"));
  do{   
  }while(!Serial.available());
  f = Serial.parseFloat();
  Serial.println(f);
}

void setup() {

  Serial.begin(9600);

  gen.Begin();              
  gen.EnableOutput(true);

  Serial.print(F("### Teste do DDS AD9833"));
  Serial.print(F("\n- Escolha a opção:"));
  Serial.print(F("\n1 - Onda senoidal"));
  Serial.print(F("\n2 - Onda triangular"));
  Serial.print(F("\n3 - Onda quadrada\n"));
}
 
void loop() {  

  if(Serial.available()){  
    
    int op = Serial.read();

    switch(op){
  
        case '1':
          configura_frequencia();
          gen.ApplySignal(SINE_WAVE,REG0,f);
          break;
  
        case '2':
          configura_frequencia();
          gen.ApplySignal(TRIANGLE_WAVE,REG0,f);
          break;
          
        case '3':
          configura_frequencia();
          gen.ApplySignal(SQUARE_WAVE,REG0,f);
          break;
  
        default:
          Serial.print(F("\nOpção errada!"));
      }
    
      Serial.print(F("\n- Escolha a opção:"));
      Serial.print(F("\n1 - Onda senoidal"));
      Serial.print(F("\n2 - Onda triangular"));
      Serial.print(F("\n3 - Onda quadrada\n"));       
  }
}
