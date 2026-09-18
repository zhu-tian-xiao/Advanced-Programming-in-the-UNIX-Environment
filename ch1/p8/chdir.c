#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void) {
    
    char buf[4096];

    // 打印当前工作目录
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("Current directory: %s\n", buf);
    }

    // 修改工作目录
    // chdir可以改变当前进程
    if (chdir("/tmp") == -1) {
        perror("chdir failed");
        return 1;
    }

    // 再次打印当前工作目录
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("After chdir: %s\n", buf);
    }

    return 0;
}