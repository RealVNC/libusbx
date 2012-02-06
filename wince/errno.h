/* Dummy file to support lack of errno.h on WinCE. */

#define ENOMEM 12
#define EBUSY  16
#define EPERM   1
#define EINVAL 22

extern int errno;
