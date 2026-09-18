#define _XOPEN_SOURCE 700
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/uio.h>

int main(void) {
  printf("maximum number of bytes in LANG environment variable: %d\n", NL_LANGMAX);

  printf("default process priority: %d\n", NZERO);

  // printf("maximum number of iovec structures that can be used with readv or writev: %d\n", _XOPEN_IOV_MAX);

  // printf("number of bytes in a filename: %d\n", _XOPEN_NAME_MAX);

  // printf("number of bytes in a pathname: %d\n", _XOPEN_PATH_MAX);
}