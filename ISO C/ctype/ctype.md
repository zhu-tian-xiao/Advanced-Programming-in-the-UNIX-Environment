# ctype.h POSIX Programmer's Manual
## NAME
ctype.h — character types
## SYNOPSIS
```c
 #include <ctype.h>
```
## DESCRIPTION
Some of the functionality described on this reference page extends the ISO C standard. Applications shall define the appropriate feature test macro (see the System Interfaces volume of POSIX.1‐2017, _Section 2.2_, _The Compilation Environment_) to enable the visibility of these symbols in this header.

The` <ctype.h>` header shall define the **locale_t** type as described in `<locale.h>`, representing a locale object.

The following shall be declared as functions and may also be defined as macros. Function prototypes shall be provided for use with ISO C standard compilers.


```c
int   isalnum(int);
int   isalnum_l(int, locale_t);
int   isalpha(int);
int   isalpha_l(int, locale_t);
int   isascii(int);
int   isblank(int);
int   isblank_l(int, locale_t);
int   iscntrl(int);
int   iscntrl_l(int, locale_t);
int   isdigit(int);
int   isdigit_l(int, locale_t);
int   isgraph(int);
int   isgraph_l(int, locale_t);
int   islower(int);
int   islower_l(int, locale_t);
int   isprint(int);
int   isprint_l(int, locale_t);
int   ispunct(int);
int   ispunct_l(int, locale_t);
int   isspace(int);
int   isspace_l(int, locale_t);
int   isupper(int);
int   isupper_l(int, locale_t);
int   isxdigit(int);
int   isxdigit_l(int, locale_t);
int   toascii(int);
int   tolower(int);
int   tolower_l(int, locale_t);
int   toupper(int);
int   toupper_l(int, locale_t);
```

The _<ctype.h>_ header shall define the following as macros:
```c
int   _toupper(int);
int   _tolower(int);
```
The following sections are informative.

# character classification functions
## NAME
isalnum,  isalpha,  isascii,  isblank, iscntrl, isdigit, isgraph, islower, isprint, ispunct, isspace, isupper,
isxdigit, isalnum_l, isalpha_l, isascii_l, isblank_l, iscntrl_l, isdigit_l, isgraph_l,  islower_l,  isprint_l,
ispunct_l, isspace_l, isupper_l, isxdigit_l - character classification functions
## SYNOPSIS
```c
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);

int isascii(int c);
int isblank(int c);

int isalnum_l(int c, locale_t locale);
int isalpha_l(int c, locale_t locale);
int isblank_l(int c, locale_t locale);
int iscntrl_l(int c, locale_t locale);
int isdigit_l(int c, locale_t locale);
int isgraph_l(int c, locale_t locale);
int islower_l(int c, locale_t locale);
int isprint_l(int c, locale_t locale);
int ispunct_l(int c, locale_t locale);
int isspace_l(int c, locale_t locale);
int isupper_l(int c, locale_t locale);
int isxdigit_l(int c, locale_t locale);

int isascii_l(int c, locale_t locale);
```
Feature Test Macro Requirements for glibc (see feature_test_macros(7)):
isascii():
_XOPEN_SOURCE
|| /* Glibc since 2.19: */ _DEFAULT_SOURCE
|| /* Glibc versions <= 2.19: */ _SVID_SOURCE

isblank():
_ISOC99_SOURCE || _POSIX_C_SOURCE >= 200112L

isalnum_l(), isalpha_l(), isblank_l(), iscntrl_l(), isdigit_l(), isgraph_l(), islower_l(), isprint_l(), is‐
punct_l(), isspace_l(), isupper_l(), isxdigit_l():
Since glibc 2.10:
_XOPEN_SOURCE >= 700
Before glibc 2.10:
_GNU_SOURCE

isascii_l():
Since glibc 2.10:
_XOPEN_SOURCE >= 700 && (_SVID_SOURCE || _BSD_SOURCE)
Before glibc 2.10:
_GNU_SOURCE

## DESCRIPTION
isgraph()
checks for any printable character except space.

islower()
checks for a lowercase character.

isprint()
checks for any printable character including space.

ispunct()
checks for any printable character which is not a space or an alphanumeric character.

isspace()
checks for white-space characters.  In the "C" and "POSIX" locales, these are: space, form-feed ('\f'),
newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and vertical tab ('\v').

isupper()
checks for an uppercase letter.

isxdigit()
checks for hexadecimal digits, that is, one of
0 1 2 3 4 5 6 7 8 9 a b c d e f A B C D E F.

## RETURN VALUE
The values returned are nonzero if the character c falls into the tested class, and zero if not.

## VERSIONS
isalnum_l(), isalpha_l(), isblank_l(), iscntrl_l(), isdigit_l(), isgraph_l(),  islower_l(),  isprint_l(),  is‐
punct_l(), isspace_l(), isupper_l(), isxdigit_l(), and isascii_l() are available since glibc 2.3.

## ATTRIBUTES
For an explanation of the terms used in this section, see attributes(7).


| Interface                                                                                                                                      | Attribute     | Value   |
| ---------------------------------------------------------------------------------------------------------------------------------------------- | ------------- | ------- |
| isalnum(), isalpha(), isascii(), isblank(), iscntrl(), isdigit(), isgraph(), islower(), isprint(), ispunct(), isspace(), isupper(), isxdigit() | Thread safety | MT-Safe |
## CONFORMING TO
C89  specifies  isalnum(),  isalpha(),  iscntrl(), isdigit(), isgraph(), islower(), isprint(), ispunct(), isspace(), isupper(), and isxdigit(), but not isascii() and isblank().  POSIX.1-2001 also specifies  those  functions,  and also isascii() (as an XSI extension) and isblank().  C99 specifies all of the preceding functions, except isascii().

POSIX.1-2008 marks isascii() as obsolete, noting that it cannot be used portably in a localized application.

POSIX.1-2008 specifies isalnum_l(),  isalpha_l(),  isblank_l(),  iscntrl_l(),  isdigit_l(),  isgraph_l(),  islower_l(), isprint_l(), ispunct_l(), isspace_l(), isupper_l(), and isxdigit_l().

isascii_l() is a GNU extension.

## NOTES
The  standards  require that the argument c for these functions is either EOF or a value that is representable in the type unsigned char.  If the argument c is of type char, it must be cast to unsigned  char,  as  in  the following example:

```c
char c;
...
res = toupper((unsigned char) c);
```

This is necessary because char may be the equivalent of signed char, in which case a byte where the top bit is set would be sign extended when converting to int, yielding a value that is  outside  the  range  of  unsigned char.

The  details  of  what characters belong to which class depend on the locale.  For example, isupper() will not recognize an A-umlaut (Ä) as an uppercase letter in the default C locale.

locale: 本地化环境（地域/语言环境）

