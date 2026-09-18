#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  dup2(4,5);
  // Bad file descriptor
  perror("dup2");
}