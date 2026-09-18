#include <math.h>
#include <complex.h>
#include <stdio.h>

int main(void) {
  double pi = 4 * atan(1);
  double complex z = cexp(I * pi);
  printf("%f + %f * i\n", creal(z), cimag(z));
}