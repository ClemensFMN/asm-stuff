#include <stdio.h>
#include <inttypes.h>

// http://cs.lmu.edu/~ray/notes/nasmtutorial/

float sumoftwo_asm(float, float);
float running_sum_asm(float[], uint64_t);


void main() {

  float s_asm = sumoftwo_asm(3.4,4.2);
  printf("%f \n", s_asm);


  // gdb debug ideas:
  // b running_sum_asm -> set breakpoint in asm file
  // p $rsi -> print second argument ( = 2)
  // x/3f $rsi -> display 3 floats at memory position of rsi 
  //			(rsi is the first parameter and is a pointer to a float array)

  float x[] = {1.1, 2.2, 5.5};
  s_asm = running_sum_asm(x, 2);
  printf("%f \n", s_asm);  

}