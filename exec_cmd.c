#include "main.h"

/**
 * execCmd - execute the command
 * @args: array of pointers to the args (vector) for the command
 * @shell: the shell program name
 * @jobNr: the sequence number of the current commands job
 * Return: 0 if all ok, else -1
 */
int execCmd(char **args, char *shell, int *jobNr)
/*int execCmd(char **cmdLine, char *shell) */
{
	int wstatus, a;
	/*char **args, pathname[PATH_MAX] = "\0"; */
	char pathname[PATH_MAX] = "\0";
	pid_t cpid;

		/*args = parseLine(*cmdLine, " \n"); */
		if (args[0])
		{
			a = getCmdPath(args, pathname, jobNr);
			if (!a)
			{
				cpid = fork();
				if (cpid == 0)
				{
					execve(pathname, args, environ);
					perror(shell);
					/*free(*cmdLine);  need to fix */
					exit(EXIT_FAILURE);
				}
				else
				{
					do {
					waitpid(cpid, &wstatus, WUNTRACED);
					} while (!WIFEXITED(wstatus) &&
						!WIFSIGNALED(wstatus));
				}
			}
		else
			{
				_printf("%s: %d: %s: not found\n", shell,
					*jobNr, args[0]);
			}
		}

		return (0);
}

