#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#define BUF_SIZE 4096
int main(int argc, char *argv[]) {
  if (argc < 2 || strcmp(argv[1], "cat") != 0) {
    exit(EXIT_FAILURE);
  }

  bool status = EXIT_SUCCESS;
  for (size_t i = 2; i < argc; i++) {
    int fd = open(argv[i], O_RDONLY);
    if (fd == -1) {
      status = EXIT_FAILURE;
      perror(argv[i]);
      continue;
    }

    char buf[BUF_SIZE];
    ssize_t n;
    while ((n = read(fd, buf, BUF_SIZE)) > 0) {
      size_t remaining = n;
      char *read_buf = buf;
      while (remaining > 0) {
        int m = write(STDOUT_FILENO, read_buf, n);
        if (m < 0) {
          perror("write error");
          exit(EXIT_FAILURE);
        }
        remaining -= m;
        read_buf += m;
      }
    }
    if (n < 0) {
      perror("read error");
      exit(EXIT_FAILURE);
    }
    if (close(fd) == -1) {
      perror("close error");
      exit(EXIT_FAILURE);
    }
  }

  exit(status);
}