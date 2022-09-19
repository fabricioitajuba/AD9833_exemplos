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

float f, fl=1000000, fh=2000000;
int tempo=10; //ms
void setup() {

  gen.Begin();              
  //gen.ApplySignal(TRIANGLE_WAVE,REG0,2000);
  //gen.ApplySignal(SINE_WAVE,REG0,1000);
  //gen.ApplySignal(SQUARE_WAVE,REG0,1000);
  //gen.ApplySignal(HALF_SQUARE_WAVE,REG0,1000);
  gen.ApplySignal(SINE_WAVE,REG0,4000000);
  gen.EnableOutput(true);   

  //gen.ApplySignal(SINE_WAVE,REG0,fl);
  //f=fl;
}
 
void loop() {
/*
  do{
    f=f+10000;
    gen.ApplySignal(SINE_WAVE,REG0,f);
    delay(tempo);
  }while(f<fh);

  do{
    f=f-10000;
    gen.ApplySignal(SINE_WAVE,REG0,f);
    delay(tempo);
  }while(f>fl);
*/
}
