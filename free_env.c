#include "main.h"

/**
 * freeEnv - free the environment variables earlier malloc'd
 *
 * @environ: pointer to the environment array
 */
void freeEnv(char **environ)
{
	int j, len = 0;
	char **ptr = environ;

	/* first establish array length */
	while (*ptr++)
		len++;

	for (j = 0; j < len; j++)
	{
		free(environ[j]);
	}
	free(environ);
}
