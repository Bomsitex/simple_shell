#include "main.h"

/**
 * execJob - execute a job, ie a batch of commands
 * @cmdLine: the shell command line
 * @argv: argument vector for the shell command line
 * @jobNr: the sequence number of the current commands job
 * Return: 0 on sucess, -1 on error
 */
int execJob(char *cmdLine, char **argv, int *jobNr)
{
	char **cmdsVector = NULL; /* the shell cmds array (job): must free*/
	char **args = NULL; /*vector of arguments in a cmd: must free */
	char *cmd = NULL; /*iterator for the cmd in the cmdsVector: must free*/
	int i = 0;

	cmdsVector = parseLine(cmdLine, ";\n", jobNr);/*free cmdsVector later*/

	/* exec the commands one at a time */
	i = 0;
	while (cmdsVector[i])
	{
		cmd = _strdup(cmdsVector[i]);  /* must free cmd later */
		remCmnt(cmd);

		/* generate args vector for this command */
		args = parseLine(cmd, " \n", jobNr);
		if (*args)  /* ie do not process blank lines! */
		{
			if (!_strcmp(args[0], "exit"))
			{
				ssExit(args, cmdLine, cmdsVector,
					cmd, argv[0], jobNr);
			}
			else
			{
			/* first try to exec builtin */
			if (execBuiltin(args, cmdLine, cmdsVector,
				cmd, argv[0], jobNr) != 0)
				execCmd(args, argv[0], jobNr);
			}
		}
		free(cmd);
		free(args); /*debug */
		i++;
	}
	free(cmdLine); /* debug */
	free(cmdsVector);
	return (0);
}

