#include <stdio.h>
#include <inttypes.h>

// http://cs.lmu.edu/~ray/notes/nasmtutorial/

int64_t maxofthree(int64_t, int64_t, int64_t);
int64_t sumoftwo_asm(int64_t, int64_t);
int64_t sumoftwo_c(int64_t, int64_t);

int64_t sumoftwo_c(int64_t a, int64_t b) {
	return a + b;
}

int64_t sumofints_c(int64_t[], int);
int64_t sumofints_asm(int64_t[], int);


int64_t sumofints_c(int64_t data[], int num) {
	int64_t sum = 0;
	for(int i=0; i<num; i++) {
		sum = sum + data[i];
	}
	return sum;
}

int64_t list_data[] = {1, 2, 3, 4, 5};

void main() {
  printf("Hello World!\n");

  //printf("%ld\n", maxofthree(2, -6, 1));

  int64_t s_c = sumoftwo_c(3,4);
  int64_t s_asm = sumoftwo_asm(3,4);

  printf("%ld, %ld\n", s_c, s_asm);

  int64_t sum_c = sumofints_c(list_data, 5);
  int64_t sum_asm = sumofints_asm(list_data, 5);

  printf("%ld, %ld\n", sum_c, sum_asm);
}