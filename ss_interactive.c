#include "main.h"

/**
 * ssInteractive - a interactive mode for a simple UNIX shell
 * @argc: number of command line arguments from main
 * @argv: arguments vector from main
 * Return: 0 on sucess, -1 on error
 */
int ssInteractive(int argc __attribute__((unused)), char **argv)
{
	char *cmdLine = NULL; /* the shell command line */
	size_t buffsz = 0; /* the cmdLine buffer size */
	ssize_t userInput = -1;  /* num of chars; -1 is error or EOF (CTRL+D)*/

	/* initiate loop */
	while (1)
	{
		/* display prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* get the command line */
		cmdLine = NULL; /*debug; reqd for cycling after cmd process?*/
		userInput = _getline(&cmdLine, &buffsz, STDIN_FILENO);
		if (userInput == -1)  /* error or EOF (CTRL+D) */
		{
			break;
		}
		/* fflush(STDIN_FILENO);  debug ? */
		execJob(cmdLine, argv);
		/* free(cmdLine);   debug */
		buffsz = 0;
	}  /* end shell loop */

	/* free resources */
	free(cmdLine);

	write(STDOUT_FILENO, "\n", 1);
	return (0);
}

