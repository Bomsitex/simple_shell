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

extern char **environ;

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
char **splitLine(char **cmdLine, char ***args);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **parseLine(char *str, char *delim);
int getCmdPath(char **args, char *pathname);
char *_getenv(const char *name);
int execCmd(char **args, char *shell);
char *remCmnt(char *cmdLine);
void shellErr(int code);
int ssInteractive(int ac, char **av);
int ssBatch(int ac, char **av);
int execJob(char *cmdLine, char **argv);
int execBuiltin(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell);
void ssExit(char **args, char *cmdLine, char **cmdsVector, char *cmd);
int cdHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell);
int envHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell);
int varHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell);

#endif /* _SIMPLE_SHELL_BK_ */

