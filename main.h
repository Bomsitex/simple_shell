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
#include <sys/wait.h>

#define BUFFSIZE 1025
#define BUFFLEN (BUFFSIZE - 1)

extern char **environ;

typedef struct stat stat_t;

/* team library functions */
void buffchar(int ch, char *buff);
int _putchar(char c);
size_t _strlen(const char *s);
char *_strncat(char *dest, char *src, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, int n);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
int _strtoi(const char *str, int *error);
char **splitLine(char **cmdLine, char ***args);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **parseLine(char *str, char *delim, int *jobNr);
int getCmdPath(char **args, char *pathnamei, int *jobNr);
char *_getenv(const char *name);
int execCmd(char **args, char *shell, int *jobNr);
char *remCmnt(char *cmdLine);
void shellErr(int code);
int ssInteractive(int ac, char **av);
int ssBatch(int ac, char **av);
int execJob(char *cmdLine, char **argv, int *jobNr);
int execBuiltin(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr);
void ssExit(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr);
int cdHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr);
int envHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr);
int varHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr);


/*printf stuff */
/* printf specific functions */
int _printf(const char *format, ...);
const char *processPercent(const char *format,
int *fpos, va_list ap, int *printCount, char *buff);
int printArg(va_list ap, char cspec, int *printCount, char *buff);
void printInt(int n, int *printCount, char *buff);
void printChar(char ch, int *printCount, char *buff);
void printString(char *s, int *printCount, char *buff);
void printStringReverse(char *s, int *printCount, char *buff);
void printStringUpper(char *s, int *printCount, char *buff);
void printUnsignedInt(unsigned int n, int *printCount, char *buff);
void printUnsignedOctal(unsigned int n, int *printCount, char *buff);
void printBinary(unsigned int n, int *printCount, char *buff);
void printHexLower(unsigned int n, int *printCount, char *buff);
void printHexUpper(unsigned int n, int *printCount, char *buff);
void printHexLowerDigits(int n, int *printCount, char *buff);
void printHexUpperDigits(int n, int *printCount, char *buff);
void printPointer(unsigned long int n, int *printCount, char *buff);
void printPointerDigits(int n, int *printCount, char *buff);
void buffchar(int ch, char *buff);
char *rot13(char *str);
void printStringRot13(char *s, int *printCount, char *buff);

#endif /* _SIMPLE_SHELL_BK_ */

