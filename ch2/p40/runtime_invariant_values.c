#define _POSIX_C_SOURCE 200809L
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("maximum length of arguments to exec functions: %ld\n", sysconf(_SC_ARG_MAX));
  
  printf("maximum number of functions that can be registered with the atexit function: %ld\n", sysconf(_SC_ATEXIT_MAX));

  printf("maximum number of child processes per real user ID: %ld\n", sysconf(_SC_CHILD_MAX));

  printf("maximum number of timer expiration overruns: %ld\n", sysconf(_SC_DELAYTIMER_MAX));

  printf("maximum length of a host name as returned by gethostname: %ld\n", sysconf(_SC_HOST_NAME_MAX));

  printf("maximum length of a login name: %ld\n", sysconf(_SC_LOGIN_NAME_MAX));

  printf("one more than the maximum value assigned to a newly created file descriptor: %ld\n", sysconf(_SC_OPEN_MAX));

  printf("system memory page size, in bytes: %ld\n", sysconf(_SC_PAGESIZE));

  printf("maximum number of real-time signals reserved for application use: %ld\n", sysconf(_SC_RTSIG_MAX));

  printf("maximum number of semaphores a process can use: %ld\n", sysconf(_SC_SEM_NSEMS_MAX));

  printf("maximum value of a semaphore: %ld\n", sysconf(_SC_SEM_VALUE_MAX));

  printf("maximum number of signals that can be queued for a process: %ld\n", sysconf(_SC_SIGQUEUE_MAX));

  printf("maximum number of standard I/O streams a process can have open at once: %ld\n", sysconf(_SC_STREAM_MAX));

  printf("number of symbolic links that can be traversed during pathname resolution: %ld\n", sysconf(_SC_SYMLOOP_MAX));

  printf("maximum number of timers per process: %ld\n", sysconf(_SC_TIMER_MAX));

  printf("length of a terminal device name, including the terminating null: %ld\n", sysconf(_SC_TTY_NAME_MAX));

  printf("number of bytes for the name of a time zone: %ld\n", sysconf(_SC_TZNAME_MAX));

}