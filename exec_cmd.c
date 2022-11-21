#include "main.h"

void printExecCmdError(char *shell, int jobNr, char *arg);

/**
 * execCmd - execute the command
 * @args: array of pointers to the args (vector) for the command
 * @shell: the shell program name
 * @jobNr: the sequence number of the current commands job
 * @lastError: last significcant error noted by the shell
 * Return: 0 if all ok, else -1
 */
int execCmd(char **args, char *shell, int *jobNr, int *lastError)
{
	int wstatus, a;
	/*char **args, pathname[PATH_MAX] = "\0"; */
	char pathname[PATH_MAX] = "\0";
	pid_t cpid;

	if (args[0])
	{
		a = getCmdPath(args, pathname, jobNr);
		/* *lastError = 0;   reset before execution */
		if (!a)
		{
			/* *lastError = 0;    reset before execution */
			errno = 0;  /* debug */
			cpid = fork();
			if (cpid == 0)
			{
				execve(pathname, args, environ);
				perror(shell);
				/*free(*cmdLine);  need to fix */
				exit(errno);  /*EXIT_FAILURE? */
			}
			else
			{
				do {
				waitpid(cpid, &wstatus, WUNTRACED);
				} while (!WIFEXITED(wstatus) &&
					!WIFSIGNALED(wstatus));
				errno = WEXITSTATUS(wstatus);/* debug */
			}
		}
	else
		{
			printExecCmdError(shell, *jobNr, args[0]);
		}
		*lastError = errno; /* debug */
	}
	return (*lastError);
}

/**
 * printExecCmdError - print the error message on aborted command
 * @shell: the simple shell program name
 * @jobNr: the serial number of this command line job
 * @arg: the offending command
 */
void printExecCmdError(char *shell, int jobNr, char *arg)
{
	char *jNr; /* free later */

	/* write the shell name */
	write(STDERR_FILENO, shell, _strlen(shell));
	write(STDERR_FILENO, ": ", 2);

	/* write the job number */
	jNr = _itostr(jobNr);
	write(STDERR_FILENO, jNr, _strlen(jNr));
	write(STDERR_FILENO, ": ", 2);
	free(jNr);

	/* write the offending argument */
	write(STDERR_FILENO, arg, strlen(arg));

	/* write the error message */
	write(STDERR_FILENO, ": not found\n", 12);
}

