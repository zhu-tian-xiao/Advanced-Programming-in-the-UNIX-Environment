#include <assert.h>
#include <stdio.h>
int main() {
  int x = 10;
  // assert(x == 10);

  // main: main.c:6: main: Assertion `x != 10' failed.
  // Aborted (core dumped)
  assert(x != 10);
  printf("program continues...\n");
}