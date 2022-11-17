#include "main.h"

/**
 * ssExit - exit module for the simple shell
 * @args: the argument vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 */

void ssExit(char **args, char *cmdLine, char **cmdsVector, char *cmd)
{
	free(cmd);
	free(args);
	free(cmdLine); /* debug */
	free(cmdsVector);

	exit(0);
}

