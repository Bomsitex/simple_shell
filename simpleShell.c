#include "main.h"

/**
 * main - a simple UNIX shell (sh) with basic features
 * @argc: number of command line arguments
 * @argv: arguments vector
 * Return: 0 on sucess, -1 on error
 */
int main(int argc, char *argv[])
{
	char *cmdLine = NULL; /* the shell command line */
	size_t buffsz = 0; /* the cmdLine buffer size */
	ssize_t userInput = -1;  /* num of chars; -1 is error or EOF (CTRL+D)*/
	char *cmdWord = NULL; /* word in the command line */
	char *av[] = {NULL , NULL };
	char *env[] = { NULL };


	(void) argc; (void) argv;  /* temporarily, until we can use these */

	/* check if we have an interactive terminal */

	/* initiate loop */

	while (1)
	{
		/* display prompt */
		write(STDOUT_FILENO, "BK ~$: ", 7);

		/* get the command line */
		userInput = getline(&cmdLine, &buffsz, stdin);
		if (userInput == -1)
			break;

		/* parse the command line into an array */
	 	cmdWord = strtok(cmdLine, " \n");
		execve(cmdWord, av, env);

		/* exec the command */

	}  /* end shell loop */

	/* free resources */
	free(cmdLine);

	write(STDOUT_FILENO, "\n", 1);
	return (0);
}


