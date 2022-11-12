#include "main.h"

int execCmd(char **cmdLine, char *shell);
/**
 * main - a simple UNIX shell (sh) with basic features
 * @argc: number of command line arguments
 * @argv: arguments vector
 * @env: environment vector of the process
 * Return: 0 on sucess, -1 on error
 */
/* gcc -Wall -pedantic -Werror -Wextra -std=gnu89 simple_shell.c*/
/*_getline.c parse_line.c _strchr.c -o */
int main(int argc, char *argv[], char *env[])
{
	char *cmdLine = NULL; /* the shell command line */
	size_t buffsz = 0; /* the cmdLine buffer size */
	ssize_t userInput = -1;  /* num of chars; -1 is error or EOF (CTRL+D)*/
	(void) argc;  /* temporarily, until we can use these */
	(void) env;  /* temporarily, until we can use these */

	/* check if we have an interactive terminal */

	/* initiate loop */
	while (1)
	{
		/* display prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/* get the command line */
		userInput = _getline(&cmdLine, &buffsz, STDIN_FILENO);
		if (userInput == -1)  /* error or EOF (CTRL+D) */
			break;

		fflush(STDIN_FILENO);

		execCmd(&cmdLine, argv[0]);
		buffsz = 0;

	}  /* end shell loop */

	/* printf("****releasing resources****\n");  debug */
	/* free resources */
	free(cmdLine);

	write(STDOUT_FILENO, "\n", 1);
	return (0);
}


/**
 * execCmd - execute the command
 * @cmdLine: pointer to the command line string
 * @shell: the shell program name
 * Return: 0 if all ok, else -1
 */

int execCmd(char **cmdLine, char *shell)
{
	int wstatus;
	char **args;
	pid_t cpid;

		args = parseLine(*cmdLine, " \n");

		cpid = fork();

		/* exec the command */
		if (cpid == 0)
		{
			if (!args[0])
				exit(EXIT_SUCCESS);
			execve(args[0], args, environ);
			perror(shell);
			free(*cmdLine);
			exit(EXIT_FAILURE);
		}
		else
		{
			do {
				waitpid(cpid, &wstatus, WUNTRACED);
			} while (!WIFEXITED(wstatus) && !WIFSIGNALED(wstatus));
		}

		/* reset resources for next cycle */
		free(args);
		args = NULL;
		free(*cmdLine);
		*cmdLine = NULL;

		return (0);
}
