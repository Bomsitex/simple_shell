#include "main.h"

/**
 * ssBatch - batch mode for a simple UNIX shell (sh)
 * @argc: number of command line arguments from main
 * @argv: arguments vector from main
 * Return: 0 on sucess, -1 on error
 */
int ssBatch(int argc  __attribute__((unused)), char **argv)
{
	char *cmdLine = NULL; /* the shell command line */
	char **args = NULL; /*vector of arguments in a cmd: must free */
	size_t buffsz = 0; /* the cmdLine buffer size */
	ssize_t userInput = -1;  /* num of chars; -1 is error or EOF (CTRL+D)*/
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	/* read and process each line until EOF */
	while (1)
	{
		userInput = _getline(&cmdLine, &buffsz, fd);
		if (userInput == -1)  /* error or EOF (CTRL+D) */
			break;

		/* fflush(STDIN_FILENO); debug ? */
		remCmnt(cmdLine);  /* test */
		args = parseLine(cmdLine, " \n");  /*debug */
		execCmd(args, argv[0]);
		/*execCmd(&cmdLine, argv[0]);*/
		free(cmdLine);/*  debug */
		free(args);  /*debug */
		cmdLine = NULL; /*debug */
		buffsz = 0;
	}
	free(cmdLine);

	return (0);
}
