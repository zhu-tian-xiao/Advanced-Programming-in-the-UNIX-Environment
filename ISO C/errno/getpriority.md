# getpriority
## NAME
getpriority, setpriority - get/set program scheduling priority
## SYNOPSIS
```c
#include <sys/time.h>
#include <sys/resource.h>

int getpriority(int which, id_t who);
int setpriority(int which, id_t who, int prio);
```
## DESCRIPTION
 The scheduling priority of the process, process group, or user, as indicated by which and who is obtained with the getpriority() call and set with the setpriority() call.  The process attribute dealt with by these system calls is the same attribute (also known as the **"nice" value**) that is dealt with by nice(2).

## RETURN VALUE
On success, getpriority() returns the calling thread's nice value, which may be a negative number.  On  error, it returns -1 and sets errno to indicate the cause of the error.

Since  a  successful  call to getpriority() can legitimately return the value -1, it is necessary to clear the external variable errno prior to the call, then check errno afterward to determine if -1 is an error or a  legitimate value.

setpriority()  returns  0 on success.  On error, it returns -1 and sets errno to indicate the cause of the error.