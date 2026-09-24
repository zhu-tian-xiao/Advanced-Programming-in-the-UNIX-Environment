#define _POSIX_C_SOURCE 200809L
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 4096
int append(int source_fd, int destination_fd);
int main(int argc, char *argv[]) {
  int status = EXIT_SUCCESS;
  if (argc != 4 || strcmp(argv[1], "append") != 0) {
    exit(EXIT_FAILURE);
  }

  int source_fd = open(argv[2], O_RDONLY);
  if (source_fd == -1) {
    perror(argv[2]);
    exit(EXIT_FAILURE);
  }

  struct stat source_stat;
  if (fstat(source_fd, &source_stat) == -1) {
    perror("fstat error");
    close(source_fd);
    exit(EXIT_FAILURE);
  }

  int destination_fd =
      open(argv[3], O_WRONLY | O_CREAT | O_APPEND, source_stat.st_mode & 0777);
  if (destination_fd == -1) {
    perror(argv[3]);
    close(source_fd);
    exit(EXIT_FAILURE);
  }

  struct stat destination_stat;
  if (fstat(destination_fd, &destination_stat) == -1) {
    perror("fstat error");
    close(source_fd);
    close(destination_fd);
    exit(EXIT_FAILURE);
  }

  if (source_stat.st_ino == destination_stat.st_ino &&
      source_stat.st_dev == destination_stat.st_dev) {
    fprintf(stderr, "ufile append: \'%s\' and \'%s\' are the same file.\n", argv[2],
            argv[3]);
    close(source_fd);
    close(destination_fd);
    exit(EXIT_FAILURE);
  }

  if (append(source_fd, destination_fd) == EXIT_FAILURE) {
    status = EXIT_FAILURE;
  }

  if (close(source_fd) == -1) {
    status = EXIT_FAILURE;
  }

  if (close(destination_fd) == -1) {
    status = EXIT_FAILURE;
  }
  return status;
}

int append(int source_fd, int destination_fd) {
  ssize_t n;
  char buf[BUF_SIZE];

  while ((n = read(source_fd, buf, BUF_SIZE)) > 0) {
    size_t remaining = n;
    char *write_buf = buf;
    while (remaining > 0) {
      ssize_t m = write(destination_fd, write_buf, remaining);
      if (m <= 0) {
        perror("write error");
        return EXIT_FAILURE;
      }
      remaining -= m;
      write_buf += m;
    }
  }
  if (n < 0) {
    perror("read error");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}