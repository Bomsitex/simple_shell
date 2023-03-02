#include "main.h"

/**
 * execBuiltin - execute a shell buitin command
 * @args: the arguments vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the simple shell program name (from main arg[0]
 * @jobNr: the sequence number of the current commands job
 * @lastError: last error monitored by the shell
 * Return: 0 if ok, -1 on error
 */
int execBuiltin(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell, int *jobNr, int *lastError)
{
	if (!_strcmp(args[0], "env"))  /* arg matches this function */
	{
		*lastError = 0;
		envHandler(args, cmdLine, cmdsVector,
		cmd, shell, jobNr, lastError);
		return (0);
	}
	else if (!_strcmp(args[0], "cd"))  /* arg matches this function */
	{
		*lastError = 0;
		cdHandler(args, cmdLine, cmdsVector,
		cmd, shell, jobNr, lastError);
		return (0);
	}
	else if ((args[1] != NULL)
		&& (!_strcmp(args[0], "echo"))
		&& (args[1][0] == '$'))	/* arg matches this function */
	{
		varHandler(args, cmdLine, cmdsVector,
		cmd, shell, jobNr, lastError);
		return (0);
	}
	else if (!_strcmp(args[0], "setenv"))  /* arg matches this function */
	{
		*lastError = 0;
		setenvHandler(args, cmdLine, cmdsVector,
		cmd, shell, jobNr, lastError);
		return (0);
	}
	else if (!_strcmp(args[0], "unsetenv"))  /* arg matches this function */
	{
		*lastError = 0;
		unsetenvHandler(args, cmdLine, cmdsVector,
		cmd, shell, jobNr, lastError);
		return (0);
	}
	return (1);
}

