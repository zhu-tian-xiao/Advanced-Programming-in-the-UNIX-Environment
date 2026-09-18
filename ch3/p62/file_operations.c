#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 512
int main(void) {
  printf("standard input: %d\n", STDIN_FILENO),
      printf("standard output: %d\n", STDOUT_FILENO);
  printf("standard error: %d\n", STDERR_FILENO);

  printf("File descriptors range from 0 through %ld\n",
         sysconf(_SC_OPEN_MAX) - 1);

  int fd1 = open("log1.txt", O_WRONLY | O_CREAT, 0644);
  char buf[] = "log: hello world\n";
  write(fd1, buf, strlen(buf));
  close(fd1);

  int fd2 = open("log2.txt", O_WRONLY | O_TRUNC);
  char buf2[] = "log: trunc txt\n";
  write(fd2, buf2, strlen(buf2));
  close(fd2);

  int fd3 = open("log3.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
  pid_t process_id = getpid();
  char buf3[BUFSIZE];
  sprintf(buf3, "log: append - process_id: %d\n", process_id);
  write(fd3, buf3, strlen(buf3));
  close(fd3);
}