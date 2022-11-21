#include "main.h"

void printExitError(char *shell, int jobNr, char *arg);

/**
 * ssExit - exit module for the simple shell
 * @args: the argument vector for the current command
 * @cmdLine: the command line for this job
 * @cmdsVector: the commands vector for this job
 * @cmd: the iterator vector for this command
 * @shell: the shell program name [argv0]
 * @jobNr: the sequence number of the current commands job
 * @lastError: last significcant error noted by the shell
 */

void ssExit(char **args, char *cmdLine,
	char **cmdsVector, char *cmd, char *shell, int *jobNr, int *lastError)
{
	/*sh: 1: exit: Illegal number: -2147483647*/
	/*sh: 1: exit: Illegal number: rt*/
	int code = 0;
	int error = -1;  /* default error code */

	/* process exec status, if any */
	if (args[1] != NULL)
	{
		/*check if it is numeric */
		code = _strtoi(args[1], &error);
		if (error || code < 0)
		{
			*lastError = ENOENT;
			printExitError(shell, *jobNr, args[1]);
			return;
		}
		*lastError = code % 256;
	}

	free(cmd);
	free(args);
	free(cmdLine); /* debug */
	free(cmdsVector);

	exit(*lastError);
}


/**
 * printExitError - print the error message on aborted exit
 * @shell: the simple shell program name
 * @jobNr: the serial number of this command line job
 * @arg: the argument to the exit command
 */
void printExitError(char *shell, int jobNr, char *arg)
{
	/*printError("%s: %d: exit: Illegal number: %s\n",  */
	char *jNr; /* free later */
	/* write the shell name */
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);


	/* write the job number */
	jNr = _itostr(jobNr);
	write(STDERR_FILENO, jNr, _strlen(jNr));
	write(STDERR_FILENO, ": ", 2);
	free(jNr);

	/* write the error message */
	write(STDERR_FILENO, "exit: Illegal number: ", 22);

	/* write the offending argument */
	write(STDERR_FILENO, arg, strlen(arg));
	write(STDERR_FILENO, "\n", 1);

}
