#include <dirent.h>
#include "../apue.h"
int main(int argc, char *argv[]) {
  DIR *dp;
  struct dirent *dirp;

  // 在这里处理argv[1]已经是shell的功能了
  // printf("%s\n", argv[1]);
  if (argc != 2) {
    err_quit("usage: ls directory_name");
  }

  if ((dp = opendir(argv[1])) == NULL) {
    err_sys("can’t open %s", argv[1]);
  }
  while ((dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }
  closedir(dp);
  exit(0);
}