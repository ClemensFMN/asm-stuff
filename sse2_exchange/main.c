#include <stdio.h>
#include <inttypes.h>

// http://cs.lmu.edu/~ray/notes/nasmtutorial/

void sum_float_asm(float[], float[]);
void sum_int_asm(uint8_t[], uint8_t[]);

void main() {

  float x[] = {1.1, 2.2, 5.5, -0.6};
  float y[] = {1.4, 2.6, 1.8, 0.6};
  sum_float_asm(x, y);

  for(int i=0; i<4; i++) {
    printf("%f \n", x[i]);
  }

  // gdb
  // b sum_int_asm
  // x/16ub $rdi
  // x/16ub $rsi
  uint8_t xi[] = {1, 22, 55, 250};
  uint8_t yi[] = {4, 26, 18, 50};
  sum_int_asm(xi, yi);

  for(int i=0; i<4; i++) {
    printf("%i \n", xi[i]);
  }


}