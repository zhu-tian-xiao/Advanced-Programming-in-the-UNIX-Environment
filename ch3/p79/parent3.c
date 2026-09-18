#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd = open("test.txt", O_CREAT | O_RDWR, 0644);
  

  // 设置 close-on-exec
  fcntl(fd, F_SETFD, FD_CLOEXEC);
  dup2(fd, 5);

  printf("exec now...\n");

  execl("./child", "child", NULL);

  perror("execl");

  return 0;
}