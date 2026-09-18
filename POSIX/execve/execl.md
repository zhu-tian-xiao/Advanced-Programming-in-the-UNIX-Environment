# execl
## NAME
execl, execlp, execle, execv, execvp, execvpe - execute a file

## SYNOPSIS

```c
#include <unistd.h>

extern char **environ;

int execl(const char *pathname, const char *arg, ...
			   /* (char  *) NULL */);
int execlp(const char *file, const char *arg, ...
			   /* (char  *) NULL */);
int execle(const char *pathname, const char *arg, ...
			   /*, (char *) NULL, char *const envp[] */);
int execv(const char *pathname, char *const argv[]);
int execvp(const char *file, char *const argv[]);
int execvpe(const char *file, char *const argv[],
			   char *const envp[]);
```

Feature Test Macro Requirements for glibc (see feature_test_macros(7)):
   execvpe(): _GNU_SOURCE

