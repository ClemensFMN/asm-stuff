#include <stdio.h>
#include <inttypes.h>

// http://cs.lmu.edu/~ray/notes/nasmtutorial/

float func1(float);

float func1(float x) {
	return 2*x;
}

float ftest = 4.678;
double dtest = 4.678;


void main() {

  float f1 = 1.46;
  float f2 = func1(f1);

  printf("%f, %f\n", f1, f2);

}