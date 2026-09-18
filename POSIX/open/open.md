# open
## NAME
open, openat, creat - open and possibly create a file
## SYNPSIS
```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);

int creat(const char *pathname, mode_t mode);

int openat(int dirfd, const char *pathname, int flags);
int openat(int dirfd, const char *pathname, int flags, mode_t mode);

/* Documented separately, in openat2(2): */
int openat2(int dirfd, const char *pathname, const struct open_how *how, size_t size);
```
Feature Test Macro Requirements for glibc (see feature_test_macros(7)):
openat():
   Since glibc 2.10:
	   _POSIX_C_SOURCE >= 200809L
   Before glibc 2.10:
	   _ATFILE_SOURCE

## DESCRIPTION
The open() system call opens the file specified by pathname.  If the specified file does not exist, it may optionally (if O_CREAT is specified in flags) be created by open().

The return value of open() is a file descriptor, a small, nonnegative integer that is used in subsequent  system  calls  (read(2),  write(2), lseek(2), fcntl(2), etc.) to refer to the open file.  The file descriptor returned by a successful call will be the lowest-numbered file descriptor not currently open for the process.

By default, the new file descriptor is set to remain open across an execve(2) (i.e., the FD_CLOEXEC  file  descriptor  flag  described in fcntl(2) is initially disabled); the O_CLOEXEC flag, described below, can be used to change this default.  The file offset is set to the beginning of the file (see lseek(2)).

A call to open() creates a new **open file description**, an entry in the system-wide table of  open  files.   The open  file  description records **the file offset and the file status flags** (see below).  A file descriptor is a reference to an open file description; this reference is unaffected if pathname  is  subsequently  removed  or modified to refer to a different file.  For further details on open file descriptions, see NOTES.


