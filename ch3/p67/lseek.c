
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
int main(void) {
  // If the file descriptor refers to a pipe, FIFO, or socket, lseek sets errno
  // to ESPIPE and returns −1.
  if (lseek(STDIN_FILENO, 0, SEEK_CUR) == -1) {
    printf("can't seek STDIN_FILENO\n");
  } else {
    printf("seek ok\n");
  }

  int fd = open("test.txt", O_WRONLY | O_CREAT, 0644);
  write(fd, "xxxxx world", 11);
  lseek(fd, 0, SEEK_CUR);
  write(fd, ", yes", 5);
  lseek(fd, 0, SEEK_SET);
  write(fd, "hello", 5);
  lseek(fd, 0, SEEK_CUR);
  write(fd, "|", 1);
  lseek(fd, 0, SEEK_END);
  write(fd, ", no\n", 5);
}