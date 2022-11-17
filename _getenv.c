#include "main.h"

/**
 * _getenv - returns a pointer to an environment variable
 *
 * @name: the environment variable to search for
 * Return: a pointer to the environment variable or NULL if not found
 */
char *_getenv(const char *name)
{
	int i = 0;

	while (environ[i])
	{
		if (!_strncmp(name, environ[i], _strlen(name)))
		{
			int c = 0;

			while (environ[i][c] != '=')
				c++;
			return (&environ[i][c + 1]);
		}
		i++;
	}

	return (NULL); /* variable not found */
}


