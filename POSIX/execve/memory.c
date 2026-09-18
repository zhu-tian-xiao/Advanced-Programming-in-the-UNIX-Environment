#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int global_init = 10;
int global_uninit;

int main() {
    int local = 20;

    void *p = malloc(100);

    printf("pid = %d\n", getpid());

    getchar(); // 暂停，方便观察
}