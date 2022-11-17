#include "main.h"

/**
 * execBuiltin - execute a shell buitin command
 * @args: the arguments vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the simple shell program name (from main arg[0]
 *
 * Return: 0 if ok, -1 on error
 */
int execBuiltin(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell)
{
	(void) shell;
	(void) args;
	(void) cmdLine;
	(void) cmdsVector;
	(void) cmd;

	if (!_strcmp(args[0], "env"))  /* arg matches this function */
	{
		envHandler(args, cmdLine, cmdsVector,
		cmd, shell);
		/*printf("envHandler\n");*/
		return (0);
	}
	else if (!_strcmp(args[0], "cd"))  /* arg matches this function */
	{
		cdHandler(args, cmdLine, cmdsVector,
		cmd, shell);
		/*printf("cdHandler\n");*/
		return (0);
	}
	else if ((args[1] != NULL)
		&& (!_strcmp(args[0], "echo"))
		&& (args[1][0] == '$'))	/* arg matches this function */
	{
		varHandler(args, cmdLine, cmdsVector,
		cmd, shell);
		/*printf("$ var replacement Handler\n"); */
		return (0);
	}

	return (1);
}

