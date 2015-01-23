#include <stdio.h>
#include <inttypes.h>

// http://cs.lmu.edu/~ray/notes/nasmtutorial/

int64_t maxofthree(int64_t, int64_t, int64_t);
int64_t sumoftwo_asm(int64_t, int64_t);
int64_t sumoftwo_c(int64_t, int64_t);

int64_t sumoftwo_c(int64_t a, int64_t b) {
	return a + b;
}


void main() {
  printf("Hello World!\n");

  //printf("%ld\n", maxofthree(2, -6, 1));

  int64_t s_c = sumoftwo_c(3,4);
  int64_t s_asm = sumoftwo_asm(3,4);

  printf("%ld, %ld\n", s_c, s_asm);

}