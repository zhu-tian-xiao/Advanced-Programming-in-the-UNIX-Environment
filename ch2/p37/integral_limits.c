#include <limits.h>
#include <stdio.h>
#include <unistd.h>
int main(void) {
  printf("bits in char: %d\n", CHAR_BIT);
  printf("max value of char: %d\n", CHAR_MAX);
  printf("min value of char: %d\n", CHAR_MIN);
  printf("max value of signed char: %d\n", SCHAR_MAX);
  printf("min value of signed char: %d\n", SCHAR_MIN);
  printf("max value of unsigned char: %d\n", UCHAR_MAX);

  printf("max value of int: %d\n", INT_MAX);
  printf("min value of int: %d\n", INT_MIN);
  printf("max value of unsigned int: %u\n", UINT_MAX);

  printf("max value of short: %d\n", SHRT_MAX);
  printf("min value of short: %d\n", SHRT_MIN);
  printf("max value of unsigned short: %u\n", USHRT_MAX);

  printf("max value of long: %ld\n", LONG_MAX);
  printf("min value of long: %ld\n", LONG_MIN);
  printf("max value of unsigned long: %lu\n", ULONG_MAX);

  printf("max value of long long: %lld\n", LLONG_MAX);
  printf("min value of long long: %lld\n", LLONG_MIN);
  printf("max value of unsigned long long %llu\n", ULLONG_MAX);

  printf("max number of bytes in a multibyte character constant: %d\n", MB_LEN_MAX);



}