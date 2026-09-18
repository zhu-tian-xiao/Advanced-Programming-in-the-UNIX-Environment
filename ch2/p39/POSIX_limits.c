#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void) {

  printf("the max length of arguments to exec functions is at least: %d\n", _POSIX_ARG_MAX);

  printf("the max number of child processes at a time per real user ID is at least: %d\n", _POSIX_CHILD_MAX);

  printf("the max number of timer expiration overruns is at least: %d\n", _POSIX_DELAYTIMER_MAX);

  printf("the max length of a host name as returned by gethostname is at least: %d\n", _POSIX_HOST_NAME_MAX);

  printf("the max number of links to a file is at least: %d\n", _POSIX_LINK_MAX);

  printf("the max length of a login name is at least: %d\n", _POSIX_LOGIN_NAME_MAX);

  printf("the max number of bytes on a terminal canonical input queue is at least: %d\n", _POSIX_MAX_CANON);

  printf("the max space available on a terminal input queue is at least: %d\n", _POSIX_MAX_INPUT);

  printf("the max number of bytes in a filename (excluding terminating null) is at least: %d\n", _POSIX_NAME_MAX);

  printf("the max number of simultaneous supplementary group IDs per process is at least: %d\n", _POSIX_NGROUPS_MAX);

  printf("the max number of open files per process is at least: %d\n", _POSIX_OPEN_MAX);

  printf("the max number of bytes in a pathname (including terminating null) is at least: %d\n", _POSIX_PATH_MAX);

  printf("the max number of bytes that can be written atomically to a pipe is at least: %d\n", _POSIX_PIPE_BUF);

  printf("the max number of repeated occurrences in a basic regular expression is at least: %d\n", _POSIX_RE_DUP_MAX);

  printf("the max number of real-time signal numbers reserved for applications is at least: %d\n", _POSIX_RTSIG_MAX);

  printf("the max number of semaphores a process can use simultaneously is at least: %d\n", _POSIX_SEM_NSEMS_MAX);

  printf("the max semaphore value is at least: %d\n", _POSIX_SEM_VALUE_MAX);

  printf("the max number of queued signals a process can send and have pending is at least: %d\n", _POSIX_SIGQUEUE_MAX);

  printf("the max value storable in an ssize_t object is at least: %d\n", _POSIX_SSIZE_MAX);

  printf("the max number of standard I/O streams open at once is at least: %d\n", _POSIX_STREAM_MAX);

  printf("the max number of bytes in a symbolic link is at least: %d\n", _POSIX_SYMLINK_MAX);

  printf("the max number of symbolic links traversed during pathname resolution is at least: %d\n", _POSIX_SYMLOOP_MAX);

  printf("the max number of timers per process is at least: %d\n", _POSIX_TIMER_MAX);

  printf("the max length of a terminal device name (including terminating null) is at least: %d\n", _POSIX_TTY_NAME_MAX);

  printf("the max length of a timezone name is at least: %d\n", _POSIX_TZNAME_MAX);

  return 0;
}