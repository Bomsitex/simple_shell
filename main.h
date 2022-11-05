#ifndef _SIMPLE_SHELL_BK_
#define _SIMPLE_SHELL_BK_

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

/* team library functions */
void buffchar(int ch, char *buff);
int _putchar(char c);
int _strlen(char *s);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);


#endif /* _SIMPLE_SHELL_BK_ */

