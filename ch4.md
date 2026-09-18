## Introduction
stat function 

stat member

attributes of a file

modify these attributes: change the owner, change the permissions...

structure of a UNIX file system

symbolic links

functions that operate on directories

function that descends through a directory hierachy

## stat, fstat, fstatat, and lstat Functions
```c
#include <sys/stat.h>
int stat(const char *restrict pathname, struct stat *restrict buf );
int fstat(int fd, struct stat *buf );
int lstat(const char *restrict pathname, struct stat *restrict buf );
int fstatat(int fd, const char *restrict pathname,
struct stat *restrict buf, int flag);
// All four return: 0 if OK, −1 on error
```

Given a pathname, the stat function returns a structure of information about the named file.


## File Types
- Regular file.
- Directory file.
- Block special file.
- Character special file.
- FIFO.
- Socket.
- Symbolic link.

| Macro      | Type of file           |
| ---------- | ---------------------- |
| S_ISREG()  | regular file           |
| S_ISDIR()  | directory file         |
| S_ISCHR()  | character special file |
| S_ISBLK()  | block special file     |
| S_ISFIFO() | pipe or FIFO           |
| S_ISLNK()  | symbolic link          |
| S_ISSOCK() | socket                 |
```c
#include "../apue.h"

int main(int argc, char* argv[]) {
  struct stat buf;
  char* ptr;
  for (int i = 1; i < argc; i++) {
    printf("%s: ", argv[i]);
    if (lstat(argv[i], &buf) < 0) {
      err_ret("lstat error");
      continue;
    }

    if (S_ISREG(buf.st_mode)) {
      ptr = "regualr";
    } else if (S_ISDIR(buf.st_mode)) {
      ptr = "directory";
    } else if (S_ISBLK(buf.st_mode)) {
      ptr = "block special";
    } else if (S_ISCHR(buf.st_mode)) {
      ptr = "character special";
    } else if (S_ISFIFO(buf.st_mode)) {
      ptr = "fifo";
    } else if (S_ISLNK(buf.st_mode)) {
      ptr = "symbolic link";
    } else if (S_ISSOCK(buf.st_mode)) {
      ptr = "socket";
    } else {
      ptr = "** unknown mode **";
    }
    printf("%s\n", ptr);
  }
  exit(0);
}
```
## Set-User-ID and Set-Group-ID
Every process has six or more IDs associated with it.


|                                       |                                        |
| ------------------------------------- | -------------------------------------- |
| real user ID, real group id           | who you really are                     |
| effective user ID, effective group ID | used for file access permission checks |
| saved set-user-ID, saved set-group-ID | saved by exec function                 |

Normally, the effective user ID equals the real user ID, and the effective group ID equals the real group ID.

Every file has an owner and a group owner. The owner is specified by the `st_uid` member of the stat structure; the group owner, by the `st_gid` member.

When we execute a program file, the effective user ID of the process is usually the real user ID, and the effective group ID is usually the real group ID. However, we can also set a special flag in the file’s mode word (`st_mode`) that says, ‘‘When this file is executed, set the effective user ID of the process to be the owner of the file (`st_uid`).’’ Similarly, we can set another bit in the file’s mode word that causes the effective group ID to be the group owner of the file (`st_gid`). These two bits in the file’s mode word are called the set-user-ID bit and the set-group-ID bit.

Returning to the stat function, the set-user-ID bit and the set-group-ID bit are contained in the file's `st_mode` value. These two bits can be tested against the constants `S_ISUID` and `S_ISGID`, respectively.

## File Access Permissions
- The first rule is that whenever we want to open any type of file by name, we must have execute permission in each directory mentioned in the name, including the current directory, if it is implied. This is why the execute permission bit for a directory is often called the search bit.
	- Note that read permission for a directory and execute permission for a directory mean different things. Read permission lets us read the directory, obtaining a list of all the filenames in the directory. Execute permission lets us pass through the directory when it is a component of a pathname that we are trying to access. (We need to search the directory to look for a specific filename.)
- The read permission for a file determines whether we can open an existing file for reading: the O_RDONLY and O_RDWR flags for the open function.
- The write permission for a file determines whether we can open an existing file for writing: the O_WRONLY and O_RDWR flags for the open function.
- We must have write permission for a file to specify the O_TRUNC flag in the open function.
- We cannot create a new file in a directory unless we have write permission and execute permission in the directory.
- To delete an existing file, we need write permission and execute permission in the directory containing the file. We do not need read permission or write permission for the file itself.
- Execute permission for a file must be on if we want to execute the file using any of the seven exec functions (Section 8.10). The file also has to be a regular file.

The file access tests that the kernel performs each time  a process opens, creates, or deletes a file depend on the owners of the file(st_uid and st_gid), the effective IDs of the process (effective user ID and effective group ID), and the supplementary group IDs of the process, if supported. The two owner IDs are properties of the file, whereas the two effective IDs and the supplementary group IDs are properties of the process. The tests performed by the kernel are as follows:

- If the effective user ID of the process is 0 (the superuser), access is allowed. This gives the superuser free rein throughout the entire file system.
- If the effective user ID of the process equals the owner ID of the file (i.e., the process owns the file), access is allowed if the appropriate user access permission bit is set. Otherwise, permission is denied. By appropriate access permission bit, we mean that if the process is opening the file for reading, the user-read bit must be on. If the process is opening the file for writing, the user-write bit must be on. If the process is executing the file, the user-execute bit must be on. 
- If the effective group ID of the process or one of the supplementary group IDs of the process equals the group ID of the file, access is allowed if the appropriate group access permission bit is set. Otherwise, permission is denied. 
- If the appropriate other access permission bit is set, access is allowed. Otherwise, permission is denied.

## Ownership of New Files and Directories
The user ID of a new file is set to the effective user ID of the process.

POSIX.1 allows an implementation to choose one of the following options to determine the group ID of a new file:
- The group ID of a new file can be the effective group ID of the process.
- The group ID of a new file can be the group ID of the directory in which the file is being created.

## access and faccessat Functions
```c
#include <unistd.h>
int access(const char *pathname, int mode);
int faccessat(int fd, const char *pathname, int mode, int flag);
// Both return: 0 if OK, −1 on error
```

```c
#include "../apue.h"
#include <fcntl.h>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    err_quit("Usage: ./a.out <pathname>");
  }

  if (access(argv[1], R_OK) < 0) {
    err_ret("access error for %s", argv[1]);
  } else {
    printf("read access OK\n");
  }

  if (open(argv[1], O_RDONLY) < 0) {
    err_ret("open error for %s", argv[1]);
  } else {
    printf("open for reading OK\n");
  }

  exit(0);
}
```
## umask Function
The umask function sets the file mode creation mask for the process and returns the previous value. (This is one of the few functions that doesn’t have an error return.)
```c
#include <sys/stat.h>
mode_t umask(mode_t cmask);
// Returns: previous file mode creation mask
```

```c
#include <fcntl.h>

#include "../apue.h"
#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
int main(void) {
  umask(0);
  if (creat("foo", RWRWRW) < 0) {
    err_sys("creat error for foo");
  }
  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (creat("bar", RWRWRW) < 0) {
    err_sys("creat error for bar");
  }
  exit(0);
}
```
## chmod, fchmod, and fchmodat Function
The chmod, fchmod, and fchmodat functions allows us to change the file access permissions for an existing file.
```c
#include <sys/stat.h>
int chmod(const char *pathname, mode_t mode);
int fchmod(int fd, mode_t mode);
int fchmodat(int fd, const char *pathname, mode_t mode, int flag);
// All three return: 0 if OK, −1 on error
```

from `<sys/stat.h>`

| mode    | Desciption                              |
| ------- | --------------------------------------- |
| S_ISUID | set-user-ID on execution                |
| S_ISGID | set-group-ID on execution               |
| S_ISVTX | saved-text(sticky bit)                  |
|         |                                         |
| S_IRWXU | read, write, and execute by user(owner) |
| S_IRUSR | read by user                            |
| S_IWUSR | write by user                           |
| S_IXUSR | execute by user                         |
|         |                                         |
| S_IRWXG | read, write, and execute by group       |
| S_IROTH | read by other(world)                    |
| S_IWOTH | write by other(world)                   |
| S_IXOTH | execute by other(world)                 |
## Sticky Bits
`S_ISVTX` bit
## chown, fchown, fchownat, and lchown Functions
The chown functions allow us to change a file’s user ID and group ID, but if either of the arguments owner or group is −1, the corresponding ID is left unchanged.

```c
#include <unistd.h>
int chown(const char *pathname, uid_t owner, gid_t group);
int fchown(int fd, uid_t owner, gid_t group);
int fchownat(int fd, const char *pathname, uid_t owner, gid_t group,
int flag);
int lchown(const char *pathname, uid_t owner, gid_t group);
// All four return: 0 if OK, −1 on error
```

These four functions operate similarly unless the referenced file is symbolic link. In that case, `lchown` and `fchownat` (with the AT_SYMLINK_NOFOLLOW flag set) change the owner of the symbolic link itself, not the file pointed to by the symbolic link.

The fchown function changes the ownership of the open file referenced by the fd argument. Since it operates on a file that is already open, it can't be used to change the ownership of a symbolic link.

下面这段有些复杂
pass
## File Size
### Holes in a File
## File Truncation
```c
#include <unistd.h>
int truncate(const char *pathname, off_t length);
int ftruncate(int fd, off_t length);
// Both return: 0 if OK, −1 on error
```
## File Systems
