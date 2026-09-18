#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#define TEST_FD 5
int main() {
  int ret = fcntl(TEST_FD, F_GETFD);

  if (ret == -1) {
    printf("fd %d does NOT exist\n", TEST_FD);
  } else {
    printf("fd %d still exists after exec\n", TEST_FD);

    int flags = fcntl(TEST_FD, F_GETFD);

    if (flags & FD_CLOEXEC) {
      printf("FD_CLOEXEC is set\n");
    } else {
      printf("FD_CLOEXEC is not set or cleared\n");
    }
  }

  return 0;
}