#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
  int fd;

  fd = open("test.txt", O_CREAT | O_RDWR, 0644);

  if (fd < 0) {
    perror("open");
    return 1;
  }

  printf("original fd = %d\n", fd);

  // 把它复制到 fd5
  dup2(fd, 5);

  printf("exec now...\n");

  execl("./child", "child", NULL);

  perror("execl");

  return 0;
}