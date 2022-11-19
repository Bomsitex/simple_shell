#include "main.h"

/**
 * ssExit - exit module for the simple shell
 * @args: the argument vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the shell program name [argv0]
 * @jobNr: the sequence number of the current commands job
 */

void ssExit(char **args, char *cmdLine,
	char **cmdsVector, char *cmd, char *shell, int *jobNr)
{
	/*sh: 1: exit: Illegal number: -2147483647*/
	/*sh: 1: exit: Illegal number: rt*/
	int code = EXIT_SUCCESS;
	int error = -1;  /* default error code */

	/* process exec status, if any */
	if (args[1] != NULL)
	{
		/*check if it is numeric */
		code = _strtoi(args[1], &error);
		if (error || code < 0)
		{
			_printf("%s: %d: exit: Illegal number: %s\n",
				shell, *jobNr, args[1]);
			return;
		}
		code = code % 256;
	}

	free(cmd);
	free(args);
	free(cmdLine); /* debug */
	free(cmdsVector);

	exit(code);
}

