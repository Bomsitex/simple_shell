#include "main.h"

/**
 * unsetenvHandler - handle setenv builtin command
 * @args: the arguments vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the simple shell program name (from main arg[0]
 * @jobNr: the sequence number of the current commands job
 * @lastError: last major error encountered
 *
 * Return: 0 if ok, -1 on error
 */
int unsetenvHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError)
{
	int argc, i;

	(void) shell;
	(void) cmdLine;
	(void) cmdsVector;
	(void) cmd;
	(void) jobNr;

	errno = 0;
	*lastError = errno;
	/* verify args are ok */
	i = 0;
	while (args[i] != NULL)
		i++;
	argc = i;

	if (argc >= 2)
	{
		/*  unset the variable */
		_unsetenv(args[1]);
		*lastError = errno;
	}

	/* now display the environment */
	/* printEnv();   debug */

	return (0);
}

