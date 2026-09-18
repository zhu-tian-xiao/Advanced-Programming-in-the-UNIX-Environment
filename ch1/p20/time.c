#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(void)
{
    /*
     * 1. 获取 Calendar time
     *
     * time_t 保存从 Epoch:
     * 1970-01-01 00:00:00 UTC
     * 到现在经过的秒数
     */
    time_t cal_time;

    cal_time = time(NULL);

    if (cal_time == (time_t)-1) {
        perror("time error");
        exit(1);
    }

    printf("Calendar time:\n");

    // 输出 Epoch 秒数
    printf("Seconds since Epoch: %ld\n", (long)cal_time);

    // 转换为人类可读格式
    printf("Human readable time: %s\n", ctime(&cal_time));


    /*
     * 2. 获取每秒 clock ticks 数量
     *
     * sysconf(_SC_CLK_TCK)
     * 返回：
     * 一秒钟包含多少个 clock ticks
     */
    long ticks_per_second;

    ticks_per_second = sysconf(_SC_CLK_TCK);

    if (ticks_per_second == -1) {
        perror("sysconf error");
        exit(1);
    }


    printf("\nProcess time information:\n");

    printf("Clock ticks per second: %ld\n",
           ticks_per_second);


    /*
     * 演示 tick 与秒的关系
     */
    printf("\nExample:\n");

    long ticks = 500;

    printf("%ld ticks equals %.2f seconds\n",
           ticks,
           (double)ticks / ticks_per_second);


    return 0;
}