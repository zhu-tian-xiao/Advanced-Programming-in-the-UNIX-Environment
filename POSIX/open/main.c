#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <stdio.h>
#include <unistd.h>
int main() {
  int file_descriptor1 = open("./a.txt", O_CREAT);
  if (file_descriptor1) {
    // open file description = file offset + file status flags
    off_t pos = lseek(file_descriptor1, 0, SEEK_CUR);
    printf("file1's file offset: %ld\n", pos);
    int flags = fcntl(file_descriptor1, F_GETFL);
    printf("file1's file flags: %x\n", flags);
    struct stat st;
    fstat(file_descriptor1, &st);

    printf("file1's inode number: %ld\n", st.st_ino);
  }
}