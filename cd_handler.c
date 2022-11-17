#include "main.h"

/**
 * cdHandler - handle the builtin cd command
 * @args: the arguments vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the simple shell program name (from main arg[0]
 *
 * Return: 0 if ok, -1 on error
 */
int cdHandler(char **args, char *cmdLine, char **cmdsVector,
	char *cmd, char *shell)
{

	(void) shell;
	(void) args;
	(void) cmdLine;
	(void) cmdsVector;
	(void) cmd;


	return (0);
}
