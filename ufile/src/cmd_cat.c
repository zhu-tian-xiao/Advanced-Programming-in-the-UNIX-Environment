#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define BUF_SIZE 4096

int cat_fd(int fd);
int main(int argc, char *argv[]) {
  if (argc < 2 || strcmp(argv[1], "cat") != 0) {
    exit(EXIT_FAILURE);
  }

  if (argc == 2) {
    return cat_fd(STDIN_FILENO);
  }

  int status = EXIT_SUCCESS;
  for (size_t i = 2; i < argc; i++) {
    int fd;
    if (strcmp(argv[i], "-") == 0) {
      fd = STDIN_FILENO;
    } else {
      fd = open(argv[i], O_RDONLY);
    }
    if (fd == -1) {
      status = EXIT_FAILURE;
      perror(argv[i]);
      continue;
    }

    if (cat_fd(fd) == EXIT_FAILURE) {
      status = EXIT_FAILURE;
    }

    if (fd != STDIN_FILENO && close(fd) == -1) {
      perror("close error");
      status = EXIT_FAILURE;
    }
  }

  return status;
}

int cat_fd(int fd) {
  char buf[BUF_SIZE];
  ssize_t n;
  while ((n = read(fd, buf, BUF_SIZE)) > 0) {
    size_t remaining = n;
    char *read_buf = buf;
    while (remaining > 0) {
      ssize_t m = write(STDOUT_FILENO, read_buf, remaining);
      if (m <= 0) {
        perror("write error");
        return EXIT_FAILURE;
      }
      remaining -= m;
      read_buf += m;
    }
  }
  if (n < 0) {
    perror("read error");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}