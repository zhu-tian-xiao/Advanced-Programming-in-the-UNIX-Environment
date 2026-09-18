#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("test.txt",
                  O_CREAT | O_RDWR,
                  0644);


    dup2(fd, 5);


    // 设置 close-on-exec
    fcntl(3, F_SETFD, FD_CLOEXEC);


    printf("exec now...\n");


    execl("./child", "child", NULL);


    perror("execl");

    return 0;
}