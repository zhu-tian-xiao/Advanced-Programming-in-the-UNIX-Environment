#include <errno.h>
#include <stdio.h>
#include <sys/resource.h>
#include <sys/time.h>
int main() {
  errno = 0;

  /* Priority limits.  */
  // #define PRIO_MIN	-20	/* Minimum priority a process can have.  */
  // #define PRIO_MAX	20	/* Maximum priority a process can have.  */

  // On success, getpriority() returns the calling thread's nice value, which may be a negative number.  On  error, it returns -1 and sets errno to indicate the cause of the error.
  int priority = getpriority(PRIO_PROCESS, 0);

  if (priority == -1 && errno != 0) {
    perror("getpriority");
    return 1;
  }

  printf("nice value = %d\n", priority);
  return 0;
}