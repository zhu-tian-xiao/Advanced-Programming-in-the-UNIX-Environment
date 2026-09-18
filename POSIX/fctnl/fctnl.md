# fctnl
## NAME
fcntl - manipulate file descriptor
## SYNOPSIS
```c
#include <unistd.h>
#include <fcntl.h>

int fcntl(int fd, int cmd, ... /* arg */ );
```

## DESCRIPTION
fctnl() performs one of the operations described below on the open file descriptor fd. The operation is determined by **cmd**.

fcntl() can take an optional third argument.  Whether or not this argument is required is determined by cmd.

### Duplicating a file descriptor
F_DUPFD (int)

Duplicate the file descriptor fd using the lowest-numbered available file descriptor greater than or equal to arg. This is different from dup(2), which uses exactly the file descriptor specified.

On success, the new file descriptor is returned.


F_DUPFD_CLOEXEC (int)

As for F_DUPFD, but additionally  set the close-on-exec flag for the duplicate file descriptor. Specifying this flag permits a program to avoid an additional fcntl() F_SETFD operation to set the FD_CLOEXEC flag.

### File descriptor flags

The  following  commands  manipulate  the flags associated with a file descriptor. Currently, only one such flag is determined: FD_CLOEXEC, the close-on-exec flag. If the FD_CLOEXEC bit is set, the file descriptor will automatically be closed during a successful execve(2). (If the execve(2) fails, the file descriptor is left open.) If the FD_CLOEXEC bit is not set, the file descriptor is not set, the file descriptor will remain open across an execve(2).

F_GETFD (void)

Return (as the function result) the file descriptor flags; arg is ignored.

F_SETFD (int)

Set the file descriptor flags to the value specified by arg.