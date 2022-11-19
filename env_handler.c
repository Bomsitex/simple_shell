#include "main.h"

/**
 * envHandler - handle the builtin env command
 * @args: the arguments vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the simple shell program name (from main arg[0]
 * @jobNr: the sequence number of the current commands job
 * Return: 0 if ok, -1 on error
 */
int envHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr)
{
	int i;
	size_t len;

	(void) shell;
	(void) args;
	(void) cmdLine;
	(void) cmdsVector;
	(void) cmd;
	(void) jobNr;

	i = 0;
	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		/*printf("%s\n", environ[i]);*/
		i++;
	}

	return (0);
}

