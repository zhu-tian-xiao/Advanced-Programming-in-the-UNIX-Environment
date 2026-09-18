# execve
## NAME
execve - execute program
## SYNOPSIS
```c
#include <unistd.h>
int execve(const char *pathname, char *const argv[],
		  char *const envp[]);
```

## DESCRIPTION
execve() executes the program referred to by pathname.  This causes the program that is currently being run by the calling process to be **replaced** with a new program, with newly initialized stack,  heap,  and  (initialized and uninitialized) data segments. 

pathname must be either a binary executable, or a script starting with a line of the form:
```
#!interpreter [optional-arg]
```
For details of the latter case, see "Interpreter scripts" below.


**argv  is  an array of pointers to strings passed to the new program as its command-line arguments.  By convention, the first of these strings (i.e., `argv[0]`) should contain the filename associated with  the  file  being executed.  The argv array must be terminated by a NULL pointer.  (Thus, in the new program,` argv[argc]` will be NULL.)**

envp is an array of pointers to strings, conventionally of the form key=value, which are passed as  the  environment of the new program.  The envp array must be terminated by a NULL pointer. 

The argument vector and environment can be accessed by the new program's main function, when it is defined as:

 ```c
 int main(int argc, char *argv[], char *envp[])
 ```

Note, however, that the use of a third argument to the main function is not specified in POSIX.1; according to POSIX.1, the environment should be accessed via the external variable environ(7).

execve() does not return on success, and the text, initialized data, uninitialized data (bss),  and  stack  of the calling process are overwritten according to the contents of the newly loaded program.

If the current program is being ptraced, a SIGTRAP signal is sent to it after a successful execve().

If  the  set-user-ID bit is set on the program file referred to by pathname, then the effective user ID of the calling process is changed to that of the owner of the program file.  Similarly, if the  set-group-ID  bit  is set on the program file, then the effective group ID of the calling process is set to the group of the program file.

The aforementioned transformations of the effective IDs are not performed  (i.e.,  the  set-user-ID  and  set-group-ID bits are ignored) if any of the following is true: