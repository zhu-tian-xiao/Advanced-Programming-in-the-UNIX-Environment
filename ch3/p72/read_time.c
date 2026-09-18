#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/times.h>
#include <sys/wait.h>
#include <unistd.h>

#include "../apue.h"
#define BIGFILE_SIZE 516581760
void copy(size_t buf_size) {
  int n;
  char* buf = malloc(buf_size);

  int fd_bigfile;
  int fd_devnull;
  if ((fd_bigfile = open("./a.bigfile", O_RDONLY)) == -1) {
    err_sys("open bigfile failed!");
  }

  if ((fd_devnull = open("/dev/null", O_WRONLY)) == -1) {
    err_sys("open /dev/null failed!");
  }

  while ((n = read(fd_bigfile, buf, buf_size)) > 0) {
    if (write(fd_devnull, buf, n) != n) {
      err_sys("write error");
    }
  }

  if (n < 0) {
    err_sys("read error");
  }

  close(fd_bigfile);
  close(fd_devnull);
  free(buf);
}
int main(void) {
  printf("BUFFSIZE\tUser CPU\tSystem CPU\tClock time\tNumber of loops\n");
  size_t buf_size = 1;

  while (buf_size <= 524288) {
    struct tms start, end;
    clock_t real_start = times(&start);

    copy(buf_size);

    clock_t real_end = times(&end);

    long ticks = sysconf(_SC_CLK_TCK);

    printf("%8ld\t%8.2f\t%8.2f\t%8.2f\t%9ld \n", buf_size,
           (double)(end.tms_utime - start.tms_utime) / ticks,
           (double)(end.tms_stime - start.tms_stime) / ticks,
           (double)(real_end - real_start) / ticks, BIGFILE_SIZE / buf_size);
    fflush(stdout);
    buf_size *= 2;
  }
}