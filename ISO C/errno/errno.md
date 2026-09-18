# errno
## NAME
errno - number of last error
## SYNOPSIS
```c
#include <errno.h>
```
## DESCRIPTION
The  `<errno.h>`  header  file defines the integer variable errno, which is set by system calls and some library functions in the event of an error to indicate what went wrong.

For some system calls and library functions (e.g., getpriority(2)), -1 is a valid return on success.  In  such cases, a successful return can be distinguished from an error return by setting errno to zero before the call, and then, if the call returns a status that indicates that an error may have occurred, checking to see if  errno has a nonzero value.

go to [[getpriority]]

errno  is  defined by the ISO C standard to be a modifiable lvalue of type int, and **must not be explicitly declared**; errno may be a macro.  errno is **thread-local**; setting it in one thread does not affect  its  value  in any other thread.

## Error numbers and names
Valid  error  numbers  are all positive numbers.  The <errno.h> header file defines symbolic names for each of the possible error numbers that may appear in errno.

All the error names specified by POSIX.1 must have distinct values, with the exception of EAGAIN  and  EWOULD‐BLOCK, which may be the same.  On Linux, these two have the same value on all architectures.

The  error  numbers  that correspond to each symbolic name **vary** across UNIX systems, and even across different architectures on Linux.  Therefore, numeric values are not included as part of the list of error names  below. The perror(3) and strerror(3) functions can be used to convert these names to corresponding textual error messages.

On any particular Linux system, one can obtain a list of all symbolic error names and the corresponding  error numbers using the errno(1) command (part of the moreutils package):

```bash
zhu@LAPTOP-2H9VOMU6:/mnt/d/Projects/Tutorial/unix$ errno -l
EPERM 1 Operation not permitted
ENOENT 2 No such file or directory
ESRCH 3 No such process
EINTR 4 Interrupted system call
EIO 5 Input/output error
ENXIO 6 No such device or address
```

```shell
zhu@LAPTOP-2H9VOMU6:/mnt/d/Projects/Tutorial/unix$ errno 2
ENOENT 2 No such file or directory
zhu@LAPTOP-2H9VOMU6:/mnt/d/Projects/Tutorial/unix$ errno ENOENT
ENOENT 2 No such file or directory
zhu@LAPTOP-2H9VOMU6:/mnt/d/Projects/Tutorial/unix$ errno -s permission
EACCES 13 Permission denied
```
## List of error names

A common mistake is to do

```c
if (somecall() == -1) {
   printf("somecall() failed\n");
   if (errno == ...) { ... }
}
```

where  errno  no  longer  needs  to  have the value it had upon return from somecall() (i.e., it may have been changed by the printf(3)).  If the value of errno should be preserved across a library call, it must be saved:

```c
if (somecall() == -1) {
   int errsv = errno;
   printf("somecall() failed\n");
   if (errsv == ...) { ... }
}
```

Note that the POSIX threads APIs do not set errno on error.  Instead, on failure they return an  error  number as  the function result.  These error numbers have the same meanings as the error numbers returned in errno by other APIs. 也就是pthread（POSIX 线程库）不通过 errno 报错，而是“直接返回错误码”。
