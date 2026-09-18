#include "../apue.h"

/**
 * 
 * 
 * 
 * 即使什么都不做，系统中的其他程序也会不断创建和销毁进程
 * zhu@zhu-dev:~/Projects/APUE/ch1/p11$ make run
 * ./process_id
 * hello world from process ID 8259
 * zhu@zhu-dev:~/Projects/APUE/ch1/p11$ make run
 * ./process_id
 * hello world from process ID 8276
 */
int main(void) {
  
  printf("hello world from process ID %ld\n", (long)getpid());
  exit(0);
}