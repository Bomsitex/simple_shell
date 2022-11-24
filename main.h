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
size_t _strlen(const char *s);
char *_strncat(char *dest, const char *src, int n);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strncmp(const char *s1, const char *s2, int n);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
int _strtoi(const char *str, int *error);
char *_itostr(int n);
char **splitLine(char **cmdLine, char ***args);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **parseLine(char *str, char *delim, int *jobNr);
int getCmdPath(char **args, char *pathnamei, int *jobNr);
char *_getenv(const char *name);
int execCmd(char **args, char *shell, int *jobNr, int *lastError);
char *remCmnt(char *cmdLine);
void shellErr(int code);
int ssInteractive(int ac, char **av);
int ssBatch(int ac, char **av);
int execJob(char *cmdLine, char **argv, int *jobNr, int *lastError);
int execBuiltin(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
void ssExit(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
int cdHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
int envHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
int varHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
int setenvHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError);
int _setenv(const char *name, const char *value, int overwrite);
int unsetenvHandler(char **args, char *cmdLine, char **cmdsVector,
        char *cmd, char *shell, int *jobNr, int *lastError);
int _unsetenv(const char *name);
int printEnv(void);
void freeEnv(char **environ);

#endif /* _SIMPLE_SHELL_BK_ */

