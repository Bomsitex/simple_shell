#include "main.h"

/**
 * execJob - execute a job, ie a batch of commands
 * @cmdLine: the shell command line
 * @argv: argument vector for the shell command line
 * Return: 0 on sucess, -1 on error
 */
int execJob(char *cmdLine, char **argv)
{
	char **cmdsVector = NULL; /* the shell cmds array (job): must free*/
	char **args = NULL; /*vector of arguments in a cmd: must free */
	char *cmd = NULL; /*iterator for the cmd in the cmdsVector: must free*/
	int i = 0;

	cmdsVector = parseLine(cmdLine, ";\n");  /* free cmdsVector later */

	/* exec the commands one at a time */
	i = 0;
	while (cmdsVector[i])
	{
		cmd = _strdup(cmdsVector[i]);  /* must free cmd later */
		remCmnt(cmd);

		/* generate args vector for this command */
		args = parseLine(cmd, " \n");
		if (!_strcmp(args[0], "exit"))
		{
			free(cmd);
			free(args);
			free(cmdLine); /* debug */
			free(cmdsVector);
			exit(0);
		}
		else
		{

		/* first try to exec builtin */
		if (execBuiltin(args, cmdLine, cmdsVector, cmd, argv[0]) != 0)
			execCmd(args, argv[0]);
		}

		free(cmd);
		free(args); /*debug */
		i++;
	}
	free(cmdLine); /* debug */
	free(cmdsVector);

	return (0);
}

