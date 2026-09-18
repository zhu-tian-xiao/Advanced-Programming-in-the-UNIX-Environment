ISO C 标准定义 C 语言和 C 标准库，标准库接口通过 24 个头文件组织。
POSIX.1 在 ISO C 的基础上定义操作系统接口，以保证 UNIX 系统之间的可移植性。
# Introduction
## UNIX Standardization
### ISO C
In late 1989, **ANSI** Standard X3.159-1989 for the C programming language was approved.

This standard was also adopted as International Standard **ISO/IEC 9899:1990**.

ANSI is the American National Standards Institute, the U.S. member in the International Organization for Standardization (ISO). 

**IEC** stands for the International Electrotechnical Commission.

The C standard is now maintained and developed by the ISO/IEC international standardization working group for the C programming language, known as ISO/IEC JTC1/SC22/WG14, or **WG14** for short.

The intent of the ISO C standard is to provide **portability** of conforming C programs to a wide variety of **operating systems**, not only the UNIX System. The standard defines not only the syntax and semantics of the programming language but also a standard library. This library is important because all contemporary UNIX Systems provide the library routines that are specified in the C standard.

In 1999, the ISO C standard was updated and approved as **ISO/IEC 9899:1999**, largely to improve support for applications that perform numerical processing.
- `restrict` keyword?

Since 1999, three technical corrigenda(错误) have been published to correct errors in the ISO C standard—one in 2001, one in 2004, and one in 2007.
- gcc ISO C standard http://gcc.gnu.org/c99status.html

The ISO C library can be divided into **24 areas**, based on the headers defined by the standard (see Figure 2.1). The POSIX.1 standard includes these headers, as well as others. As Figure 2.1 shows, all of these headers are supported by the four implementations (FreeBSD 8.0, Linux 3.2.0, Mac OS X 10.6.8, and Solaris 10) that are described later in this chapter.

```bash
zhu@laptop:/usr/lib/x86_64-linux-gnu$ ldd --version
ldd (Ubuntu GLIBC 2.35-0ubuntu3.13) 2.35
Copyright (C) 2022 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
Written by Roland McGrath and Ulrich Drepper.
```
说明wsl(ubuntu22)的ISO C library的实现是GLIBC
```bash
zhu@laptop:/mnt/d/Project/Tutorial/unix/ch1/p19_sig_int$ ldd sig_int
        linux-vdso.so.1 (0x00007ffcfd1af000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x000071ead6c00000)
        /lib64/ld-linux-x86-64.so.2 (0x000071ead6e6d000)
```
ldd可以看出链接了哪些动态链接库


### IEEE POSIX
POSIX is a family of standards initially developed by the IEEE (Institute of Electrical and Electronics Engineers). POSIX stands for **Portable Operating System Interface**. It originally referred only to the **IEEE Standard 1003.1-1988** — the operating systeminterface — but was later extended to include many of the standards and draft standards
with the 1003 designation, including the shell and utilities (1003.2).

Of specific interest to this book is the **1003.1** operating system interface standard, whose goal is to **promote the portability of applications among various UNIX System environments**. This standard defines the services that an operating system must provide if it is to be ‘‘POSIX compliant,’’ and has been adopted by most computer vendors. Although the 1003.1 standard is based on the UNIX operating system, the standard is not restricted to UNIX and UNIX-like systems. Indeed, some vendors supplying proprietary operating systems claim that these systems have been made POSIX compliant, while still leaving all their proprietary features in place.

Because the 1003.1 standard specifies an interface and not an implementation, no distinction is made between system calls and library functions. All the routines in the standard are called functions.

Standards are continually evolving, and the 1003.1 standard is no exception. The 1988 version, **IEEE Standard 1003.1-1988**, was modified and submitted to the International Organization for Standardization. **No new interfaces or features were added**, but the text was revised. The resulting document was published as **IEEE Standard 1003.1-1990 `[IEEE 1990]`**. This is also International Standard **ISO/IEC 9945-1:1990**. This standard was commonly referred to as ***POSIX.1***, a term which we’ll use in this text to refer to the different versions of the standard.

The IEEE 1003.1 working group continued to make changes to the standard. In 1996, a revised version of the IEEE 1003.1 standard was published. It included the 1003.1-1990 standard, the 1003.1b-1993 real-time extensions standard, and the interfaces for multithreaded programming, called **pthreads** for POSIX threads. This version of the standard was also published as International Standard **ISO/IEC 9945-1:1996**. More real-time interfaces were added in 1999 with the publication of **IEEE Standard 1003.1d-1999**. A year later, **IEEE Standard 1003.1j-2000** was published, including even more real-time interfaces, and **IEEE Standard 1003.1q-2000** was published, adding event-tracing
extensions to the standard.

The 2001 version of 1003.1 departed from the prior versions in that it combined several 1003.1 amendments, the 1003.2 standard, and portions of the Single UNIX Specification (SUS), Version 2 (more on this later). The resulting standard, **IEEE Standard 1003.1-2001**, included the following other standards:


- ISO/IEC 9945-1 (IEEE Standard 1003.1-1996), which includes
	- IEEE Standard 1003.1-1990
	- IEEE Standard 1003.1b-1993 (real-time extensions)
	- IEEE Standard 1003.1c-1995 (pthreads)
	- IEEE Standard 1003.1i-1995 (real-time technical corrigenda)
- IEEE P1003.1a draft standard (system interface amendment)
- IEEE Standard 1003.1d-1999 (advanced real-time extensions)
- IEEE Standard 1003.1j-2000 (more advanced real-time extensions)
- IEEE Standard 1003.1q-2000 (tracing)
- Parts of IEEE Standard 1003.1g-2000 (protocol-independent interfaces)
- ISO/IEC 9945-2 (IEEE Standard 1003.2-1993)
- IEEE P1003.2b draft standard (shell and utilities amendment)
- IEEE Standard 1003.2d-1994 (batch extensions)
- The Base Specifications of the Single UNIX Specification, version 2, which include
	- System Interface Definitions, Issue 5
	- Commands and Utilities, Issue 5
	- System Interfaces and Headers, Issue 5
- Open Group Technical Standard, Networking Services, Issue 5.2
- ISO/IEC 9899:1999, Programming Languages–C

In 2004, the POSIX.1 specification was updated with technical corrections; more comprehensive changes were made in 2008 and released as Issue 7 of the Base Specifications. ISO approved this version at the end of 2008 and published it in 2009 as International Standard ISO/IEC 9945:2009. It is based on several other standards:
- IEEE Standard 1003.1, 2004 Edition
- Open Group Technical Standard, 2006, Extended API Set, Parts 1–4
- ISO/IEC 9899:1999, including corrigenda

In this text we describe the 2008 edition of POSIX.1. Its interfaces are divided into required ones and optional ones（可选接口不是必须要所有系统实现）. The optional interfaces are further divided into 40 sections, based on functionality. The sections containing nonobsolete programming interfaces are summarized in Figure 2.5 with their respective option codes. Option codes are two- to three-character abbreviations that identify the interfaces that belong to each functional area and highlight text describing aspects of the standard that depend on the support of a particular option. Many options deal with real-time extensions.

POSIX.1 **does not include the notion of a superuser**. Instead, certain operations require ‘‘**appropriate privileges**,’’ although POSIX.1 leaves the definition of this term up to the implementation. UNIX systems that conform to the Department of Defense’s security guidelines have many levels of security. In this text, however, we use the traditional terminology and refer to operations that require superuser privilege.
也就是说POSIX没有定义root用户，只是宽泛的定义“合适的优先级”，但是习惯上仍然用UNIX的root/superuser说法。

### The Single UNIX Specification
The Single UNIX Specification, a subset of the POSIX.1  standard, specifies additional interfaces that extend the functionality provided by the POSIX.1 specification. POSIX.1 is equivalent to the Base Specifications portion of the Single UNIX Specification.

The X/Open System Interfaces (XSI) option in POSIX.1 describes optional interfaces and defines which optional portions of POSIX.1 must be supported for an implementation to be deemed XSI conforming. These include file synchronization, thread stack address and size attributes, thread process-shared synchronization, and the `_XOPEN_UNIX` symbolic constant (marked ‘‘SUS mandatory’’ in Figure 2.5). Only XSI- conforming implementations can be called UNIX systems.

简单概括：
ISO C 定义标准 C 语言和标准库。  
  
POSIX负责操作系统（unix）接口，  
并把接口分为 required（必选）和 optional（可选）两部分。  
  
XSI（X/Open System Interfaces）  
从 POSIX 的 optional interfaces 中，  
挑选出一部分重要功能，  
要求实现必须支持。  
  
SUS（Single UNIX Specification）  
基本上就是：  
POSIX + XSI + 更严格的统一行为规范。  
  
一个系统如果想被正式称为 UNIX，  
就必须满足 SUS/XSI 的要求。
### FIPS
pass
## UNIX System Implementations
One at AT&T that led to System III and System V, the so-called commercial versions of the UNIX System.

One at the University of California at Berkeley that led to the 4.xBSD implementations.

The research version of the UNIX System, developed at the Computing Science
Research Center of AT&T Bell Laboratories, that led to the UNIX Time-Sharing System 8th Edition, 9th Edition, and ended with the 10th Edition in 1990.
## Relationship of Standards and Implementations

## Limits
The implementations define many **magic numbers and constants**. 

Two types of limits are needed:
1. Compile limits
2. Runtime limits

Additionally, some limits can be fixed on a given implementation—and could therefore be defined statically in a header—yet vary on another implementation and would require a runtime function call. An example of this type of limit is the maximum number of bytes in a filename. Before SVR4, System V historically allowed only 14 bytes in a filename, whereas BSD-derived systems increased this number to 255. Most UNIX System implementations these days support multiple file system types, and each type has its own limit. This is the case of a runtime limit that depends on where in the file system the file in question is located. A filename in the root file system, for example, could have a 14-byte limit, whereas a filename in another file system could have a 255-byte limit.

To solve these problems, three types of limits are provided:
- **Compile-time limits (headers)**
- **Runtime limits not associated with a file or directory (the sysconf function)**
- **Runtime limits that are associated with a file or a directory (the pathconf and fpathconf functions)**


To further confuse things, if a particular runtime limit does not vary on a given system, it can be defined statically in a header. If it is not defined in a header, however, the application must call one of the **three conf** functions (which we describe shortly) to determine its value at runtime.

### ISO C Limits
对于UNIX64的情况
```bash
zhu@laptop:/mnt/d/Project/Tutorial/unix/ch2/p37$ ./integral-value
bits in char: 8
max value of char: 127
min value of char: -128
max value of signed char: 127
min value of signed char: -128
max value of unsigned char: 255
max value of int: 2147483647
min value of int: -2147483648
max value of unsigned int: 4294967295
max value of short: 32767
min value of short: -32768
max value of unsigned short: 65535
max value of long: 9223372036854775807
min value of long: -9223372036854775808
max value of unsigned long: 18446744073709551615
max value of long long: 9223372036854775807
min value of long long: -9223372036854775808
max value of unsigned long long 18446744073709551615
max number of bytes in a multibyte character constant: 16
```
如果是Windows，情况会不同
```bash
bits in char: 8
max value of char: 127
min value of char: -128
max value of signed char: 127
min value of signed char: -128
max value of unsigned char: 255
max value of int: 2147483647
min value of int: -2147483648
max value of unsigned int: 4294967295
max value of short: 32767
min value of short: -32768
max value of unsigned short: 65535
max value of long: 2147483647
min value of long: -2147483648
max value of unsigned long: 4294967295
max value of long long: 9223372036854775807
min value of long long: -9223372036854775808
max value of unsigned long long 18446744073709551615
max number of bytes in a multibyte character constant: 5
```
On a 64-bit system, the values for long integer maximums match the maximum values for long long integers.
这里是针对UNIX系统来说的，也就是LP64，但是对于Windows系统并不是这样

Another ISO C constant that we’ll encounter is FOPEN_MAX, the minimum number of standard I/O streams that the implementation guarantees can be open at once. This constant is found in the <stdio.h> header, and its minimum value is 8. The POSIX.1 value STREAM_MAX, if defined, must have the same value as FOPEN_MAX.
这里的STREM_MAX在很多系统中是不在编译器定义的
```c
printf("minimum number of standard I/O streams that the implementation gurantees can be open at once: %d\n"

    "STREAM_MAX has the same value: %ld\n", FOPEN_MAX, sysconf(_SC_STREAM_MAX));
```
在wsl中
```bash
minimum number of standard I/O streams that the implementation gurantees can be open at once: 16
STREAM_MAX has the same value: 16
```
ISO C also defines the constant TMP_MAX in <stdio.h>. It is the maximum number of unique filenames generated by the tmpnam function. We’ll have more to say about this constant in Section 5.13.

```bash
the maximum number of unique filenames generated by the tmpnam function: 238328
```

Although ISO C defines the constant FILENAME_MAX, we avoid using it, because POSIX.1 provides better alternatives (NAME_MAX and PATH_MAX). We’ll see these constants shortly.

```bash
max filename: 4096
```
### POSIX Limits
- Numerical limits: LONG_BIT, SSIZE_MAX, and WORD_BIT
- Minimum values: the 25 constants in Figure 2.8
- Maximum value: _POSIX_CLOCKRES_MIN
- Runtime increasable values: CHARCLASS_NAME_MAX, COLL_WEIGHTS_MAX, LINE_MAX, NGROUPS_MAX, and RE_DUP_MAX
- Runtime invariant values, possibly indeterminate: the 17 constants in Figure 2.9(plus an additional four constants introduced in Section 12.2 and three constants introduced in Section 14.5)
- Other invariant values: NL_ARGMAX, NL_MSGMAX, NL_SETMAX, and NL_TEXTMAX
- Pathname variable values: FILESIZEBITS, LINK_MAX, MAX_CANON, MAX_INPUT, NAME_MAX, PATH_MAX, PIPE_BUF, and SYMLINK_MAX


For example, a particular value may not be included in the header if its actual value for a given process depends on the amount of memory on the system. If the values are not defined in the header, we can’t use them as array bounds at compile time. To determine the actual implementation value at runtime, POSIX.1 decided to provide three functions for us to call—**sysconf, pathconf, and fpathconf**. There is still a problem, however, because some of the values are defined by POSIX.1 as being possibly ‘‘**indeterminate**’’ (logically infinite). This means that the value has no practical upper bound. On Solaris, for example, the number of functions you can register with atexit to be run when a process ends is limited only by the amount of memory on the system. Thus ATEXIT_MAX is considered indeterminate on Solaris. We’ll return to this problem of indeterminate runtime limits in Section 2.5.5.

### XSI Limits
```c
#define _XOPEN_SOURCE 700
#include <limits.h>
#include <stdio.h>
#include <unistd.h>
int main(void) {
  printf("maximum number of bytes in LANG environment variable: %d\n", NL_LANGMAX);

  printf("default process priority: %d\n", NZERO);

  // printf("maximum number of iovec structures that can be used with readv or writev: %d\n", _XOPEN_IOV_MAX);

  // printf("number of bytes in a filename: %d\n", _XOPEN_NAME_MAX);

  // printf("number of bytes in a pathname: %d\n", _XOPEN_PATH_MAX);
}
```
部分的参数不被现代Linux支持

### sysconf, pathconf, and fpathconf Functions

```c
#include <unistd.h>

long sysconf(int name);

long pathconf(const char *pathname, int name);

long fpathconf(int fd, int name);
// All three return: corresponding value if OK, −1 on error (see later)
```
### Indeterminate Runtime Limits
pass
## Feature Test Macros
The headers define numerous POSIX.1 and XSI symbols, as we’ve described. Even so, most implementations can add their own definitions to these headers, in addition to the POSIX.1 and XSI definitions.
```c
#define _POSIX_C_SOURCE
200809L
```

```bash
gcc -D_XOPEN_SOURCE=700 -std=c99 file.c -o file
```

## Primitive System Data Types
The header `<sys/types.h>` defines some implementation-dependent data types, called the primitive system data types.

By defining these data types this way, we do not build into our programs implementation details that can change from one system to another.

## Differences Between Standards
## Exercises
1.
```c
#ifndef 
#define 

#endif
```