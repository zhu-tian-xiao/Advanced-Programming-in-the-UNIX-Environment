# UNIX System Over view
## Introduction
## UNIX Architecture
The interface to the kernel is a layer of software called the system calls (the shaded portion in Figure 1.1). Libraries of common functions are built on top of the system call interface, but applications are free to use both. The shell is a special application that provides an interface for running other applications.
这里的other applications指的是ls cat这种程序。
## Logging In
### Login Name
查看password file
```c
cat /etc/passwd
```

the login name, encrypted password, numeric user ID (205), numeric group ID (105), a comment field, home directory (/home/sar), and shell program (/bin/ksh).
```c
zhu:x:1000:1000:,,,:/home/zhu:/bin/bash
```
### Shells
A shell is a command-line **interpreter** that reads user input and executes commands. The user input to a shell is normally from the terminal (an interactive shell) or sometimes from a file (called a shell script).

The system knows which shell to execute for us based on the final field in our entry in the password file.
```bash
cat /etc/passwd
```
在这里是`/bin/bash`，是用户默认的登陆shell


或者也可以直接用
```shell
echo $SHELL
```
这两者表示的含义相同

也可以使用别的shell，比如sh，就会进入
```shell
$ 
```
界面，用exit可以回退到`/bin/bash`

```shell
ps -p $$
```
```shell
echo $0
```
都可以查找目前所在的shell
## Files and Directories
### File System
The UNIX file system is a hierarchical arrangement of directories and files. Everything starts in the directory called **root**, whose name is the single character /.

A directory is a file that contains directory entries.

### Filename
The only two characters that cannot appear in a filename are the slash character (/) and the null character.

The slash separates the filenames that form a pathname (described next) and the null character terminates a pathname.
Unix 文件名是用 C 字符串表示的，而 C 字符串以 '\0' 终止，所以文件名不能包含 '\0'。
### Pathname
A sequence of one or more filenames, separated by slashes and optionally starting with a slash, forms a pathname.

The name for the root of the file system (/) is a special-case absolute pathname that has no filename component.
### Example #important
```c++
#include <dirent.h>

#include "apue.h"
int main(int argc, char* argv[]) {
  DIR* dp;
  struct dirent* dirp;

  if (argc != 2) {
    err_quit("usage: ls directory_name");
  }
  
  if ((dp = opendir(argv[1])) == NULL) {
    err_sys("can’t open %s", argv[1]);
  }
  while ((dirp = readdir(dp)) != NULL) {
    printf("%s\n", dirp->d_name);
  }
  closedir(dp);
  exit(0);
}
```
- opendir readdir closedir的声明都在dirent.h中, dirent structure也被定义在该头文件中

opendir: Open a directory stream on NAME. Return a DIR stream on the directory, or NULL if it could not be opened.
这里的directory stream指的是用来“顺序读取目录项”的流


### Working Directory
Every process has a working directory, sometimes called the current working directory. This is the directory from which all relative pathnames are interpreted.

用chdir可以改变进程的working directory

```c
/* Change the process's working directory to PATH.  */
extern int chdir (const char *__path) __THROW __nonnull ((1)) __wur;
```

```c
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int main(void) {
    
    char buf[4096];

    // 打印当前工作目录
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("Current directory: %s\n", buf);
    }

    // 修改工作目录
    // chdir可以改变当前进程
    if (chdir("/tmp") == -1) {
        perror("chdir failed");
        return 1;
    }

    // 再次打印当前工作目录
    if (getcwd(buf, sizeof(buf)) != NULL) {
        printf("After chdir: %s\n", buf);
    }

    return 0;
}
```

### Home Directory
When we log in, the working directory is set to our home directory.
```bash
cat /etc/passwd
```
里面又用户的home directory
```bash
zhu:x:1000:1000:,,,:/home/zhu:/bin/bash
```
## Input and Output
### File Descriptors
File descriptors are normally **small non-negative integers** that the **kernel** uses to identify the files accessed by a process. Whenever it opens an existing file or creates a new file, the kernel returns a file descriptor that we use when we want to read or write the file.
### Standard Input, Standard Output, and Standard Error
By convention, all **shells** open three descriptors whenever a new program is run: standard input, standard output, and standard error.

```bash
ls > file.list
```
### Unbuffered I/O
Unbuffered I/O is provided by the functions open, `read`, `write`, `lseek`, and `close`. These functions all work with file descriptors.
### Example
```c
#include "apue.h"
#define BUFFSIZE 4096
int main(void) {
  int n;
  char buf[BUFFSIZE];
  while ((n = read(STDIN_FILENO, buf, BUFFSIZE)) > 0) {
    if (write(STDOUT_FILENO, buf, n) != n) {
      err_sys("write error");
    }
  }
  if (n < 0) {
    err_sys("read error");
  }
  exit(0);
}
```
### Standard I/O
The standard I/O functions provide a **buffered interface** to the unbuffered I/O functions.  Using standard I/O relieves us from having to choose optimal(最佳的) buffer sizes, such as the BUFFSIZE constant in Figure 1.4.

### Example
```c
#include "../apue.h"
int main(void) {
  int c;
  while ((c = getc(stdin)) != EOF) {
    {
      if (putc(c, stdout) == EOF) {
        err_sys("output error");
      }
    }
  }
  if (ferror(stdin)) {
    err_sys("input error");
  }
  exit(0);
}
```
## Programs and Processes
### Program
A program is an **executable** file residing on a disk in a directory. A program is read into memory and is executed by the **kernel** as a result of one of the seven exec functions.
### Processes and Process ID
An **executing instance** of a program is called a process.

The UNIX System guarantees that every process has a unique numeric identifier called the process ID.
### Example
```c
int main(void) {
  printf("hello world from process ID %ld\n", (long)getpid());
  exit(0);
}
```
### Process Control
fork, exec, and waitpid

The exec function has seven variants
### Example
This is a bare-bones implementation of a **shell-like** program.
```c
int main(void) {
  char buf[MAXLINE];

  pid_t pid;
  int status;

  printf("%% ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    if ((pid = fork()) < 0) {
      // exit(1)
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%% ");
  }
}
```
### Threads and Thread IDs
Usually, a process has only one thread of control — one set of machine instructions executing at a time. ...
## Error Handling
```c
extern int *__errno_location (void) __THROW __attribute_const__;
# define errno (*__errno_location ())
```

```c
#include <string.h>
/* Return a string describing the meaning of the `errno' code in ERRNUM.  */
extern char *strerror (int __errnum) __THROW;
```

```C
/* Print a message describing the meaning of the value of errno.

   This function is a possible cancellation point and therefore not
   marked with __THROW.  */
extern void perror (const char *__s);
```

```c
#define ENOENT     2  /* No such file or directory */
#define EACCES    13  /* Permission denied */
```
### Example
```c
#include "../apue.h"
#include <errno.h>

int main(int argc, char *argv[]) {
  fprintf(stderr, "EACCES: %s\n", strerror(EACCES));
  errno = ENOENT;
  perror(argv[0]);
  exit(0);
}
```
Note that we pass the name of the program—argv[0], whose value is ./a.out—as the argument to perror. This is a standard convention in the UNIX System. By doing this, if the program is executed as part of a pipeline, as in
```shell
prog1 < inputfile | prog2 | prog3 > outputfile
```
we are able to tell which of the three programs generated a particular error message.
### Error recovery
The errors defined in <errno.h> can be divided into two categories: fatal and nonfatal.

A fatal error has no recovery action. 

Nonfatal errors, can sometimes be dealt with more robustly. Most nonfatal errors are temporary, such as a resource shortage, and might not occur when there is less activity on the system.
## User Identification
## User ID
The user ID from our entry in the password file is a numeric value that identifies us to the system. The user ID is assigned by the system adminstrator when our login name is assigned, and we can't change it.

We call the user whose user ID is 0 either root or superuser.
### Group ID
Our entry in the password file also specifies our numeric group ID. This, too, is assigned by the system administrator when our login name is assigned.

Groups are normally used to collect users together into projects or departments. This allows the sharing of resources, such as files, among members of the same group. 

There is also a group file that maps group names into numeric group IDs. The group file is usually `/etc/group`.

The use of numeric user IDs and numeric group IDs for permissions is historical. With every file on disk, the file system stores both the user ID and the group ID of a file's owner. ... If the full ASCII login name and group name were used instead, additional disk space would be required. In addition, comparing permission checks is more expensive than comparing integers

Users, however, work better with names than with numbers, so the password file maintains the mapping between login names and user IDs, and the group file provides the mapping between group names and group IDs. The `ls -l `command, for example, prints the login name of the owner of a file, using the password file to map the numeric user ID into the corresponding login name.

```c
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("uid = %d, gid = %d\n", getuid(), getgid());
  exit(0);
}
```
### Supplementary Group IDs
In addition to the group ID specified in the password file for a login name, most versions of the UNIX System allow a user to belong to other groups.
## Signals
Signals are a technique used to notify a process that some condition has occurred.

The process has three choices for dealing with the signal.

1. Ignore the signal. This option isn’t recommended for signals that denote a hardware exception.
2. Let the default action occur. For a divide-by-zero condition, the default is to terminate the process.
3. Provide a function that is called when the signal occurs (this is called ‘‘catching’’ the signal). By providing a function of our own, we’ll know when the signal occurs and we can handle it as we wish.

```c
static void sig_int(int);
/* our signal-catching function */
#include <sys/wait.h>

#include "../apue.h"

int main(void) {
  char buf[MAXLINE];

  pid_t pid;
  int status;

  if (signal(SIGINT, sig_int) == SIG_ERR) {
    err_sys("signal error");
  }
  printf("%% ");
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf) - 1] == '\n') {
      buf[strlen(buf) - 1] = 0;
    }

    if ((pid = fork()) < 0) {
      err_sys("fork error");
    } else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      err_ret("couldn't execute: %s", buf);
      exit(127);
    }

    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%% ");
  }
}

void sig_int(int signo) {
  printf("interrupt\n%% ");
}
```
ctrol-D: eof

## Time values
UNIX systems have maintained two different time values:
1. Calendar time.
2. Process time.

UNIX System maintains three values for a process:
- clock time.
- User CPU time.
- System CPU time.


```bash
zhu@laptop:/usr/include$ time -p grep _POSIX_SOURCE */*.h > /dev/null
real 1.18
user 0.02
sys 0.11
```

grep是文本搜索命令，`_POSIX_SOURCE`是待搜索的文本
所以这部分命令的作用是：  
在当前目录的每个子目录下，搜索所有 `.h` 文件中包含 `_POSIX_SOURCE` 的行。

`/dev/null`是特殊设备文件，表示写入它的数据会被直接丢弃。

## System Calls and Library Functions
All implementations of the UNIX System  provide a well-defined, limited number of entry points directly into the kernel called **system calls**.

The system call interface has always been documented in **Section 2** of the UNIX Programmer's Manual. Its definition is in the C language, no matter which implementation technique is actually used on any given system to invoke a system call.

The technique used on UNIX systems is for each system call to have a function of the same name in the standard C library.

Section 3 of the UNIX Programmer's Manual defines the general-purpose library functions available to programmers.



## Summary
pass