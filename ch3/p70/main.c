#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void) {
  printf("%ld\n", sysconf(_SC_V7_ILP32_OFF32));
  printf("%ld\n", sysconf(_SC_V7_ILP32_OFFBIG));
  printf("%ld\n", sysconf(_SC_V7_LP64_OFF64));
  // printf("%ld\n", sysconf(_SC_V7_LP64_OFFBIG));
}