#include "main.h"

/**
 * printEnv - print the environment
 * Return: 0 if ok, -1 on error
 */
int printEnv(void)
{
	int i;
	size_t len;

	i = 0;
	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}

	return (0);
}

