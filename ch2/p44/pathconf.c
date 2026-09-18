#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
int main(void) {
  int fd = open("./test.txt", O_RDWR);

  if (fd == -1) {
    perror("open failed");
    return 1;
  }

  printf("open success!\n");

  printf("该文件系统支持的最大文件大小需要多少位来表示: %ld\n",
         pathconf("./test.txt", _PC_FILESIZEBITS));

  printf("maximum value of a file's link count: %ld\n",
         pathconf("./test.txt", _PC_LINK_MAX));

  printf(
      "maximum number of bytes on a terminal's canonical input "
      "queue(这里以标准输入为例): %ld\n",
      fpathconf(STDIN_FILENO, _PC_MAX_CANON));

  printf(
      "number of bytes for which space is available on terminal’s input "
      "queue: %ld\n",
      fpathconf(STDIN_FILENO, _PC_MAX_INPUT));

  printf(
      "maximum number of bytes in a filename(does not include a null at "
      "end): %ld\n",
      pathconf("../p44", _PC_NAME_MAX));
  printf(
      "maximum number of bytes in a filename(does not include a null at "
      "end): %ld\n",
      pathconf("/mnt", _PC_NAME_MAX));

  printf(
      "maximum number of bytes in a relative pathname, including the "
      "terminating null: %ld\n",
      pathconf("../p44", _PC_PATH_MAX));

  printf(
      "maximum number of bytes that can be written atomically to a pipe: %ld\n",
      pathconf("../p44", _PC_PIPE_BUF));

  // 这个参数不支持
  // printf("resolution in nanoseconds for file timestamps: %ld\n",
  // pathconf("./test.txt", _PC_TIMESTAMP_RESOLUTION));

  printf("number of bytes in a symbolic link: ");
  long ret = pathconf("../p44", _PC_SYMLINK_MAX);
  if (ret == -1) {
    if (errno == 0)
      printf("no limit\n");
    else
      perror("pathconf");
  } else {
    printf("%ld\n", ret);
  }
  return 0;
}