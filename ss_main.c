#include "main.h"


int  createEnv(char ***environ);
void doFree(char **env, int i);

/**
 * main - a simple UNIX shell (sh) with basic features
 * @argc: number of command line arguments
 * @argv: arguments vector
 * Return: 0 on sucess, -1 on error
 */
int main(int argc, char *argv[])
{
	int lastError = 0;

	/* migreate environ to a malloc'ed array */
	createEnv(&environ); /* must free environ before program exit */

	if (argc == 1)
		lastError = ssInteractive(argc, argv);
	else
		lastError = ssBatch(argc, argv);

	return (lastError);
}

/**
 * createEnv - create and fill a dynamic array for environ
 * @environ: pointer to the environ
 * Return: the number of variables in the environment created
 */
int createEnv(char ***environ)
{
	int len = 0, i = 0;
	char **env = *environ;

	/* get environ size */
	while (*env++)
		i++;
	len = i;
	/* allocate memory for len pointers for environ */
	env = malloc(sizeof(char *) * (len + 1));
	if (env == NULL)
	{
		perror("createEnv");
		exit(EXIT_FAILURE);
	}

	/* allocate memory for each variable and copy data */
	for (i = 0; i < len; i++)
	{
		env[i] = malloc(sizeof(char) * (_strlen((*environ)[i]) + 1));
		if ((*environ)[i] == NULL)
		{
			doFree(env, i);
			perror("createEnv");
			exit(EXIT_FAILURE);
		}
		_strcpy(env[i], (*environ)[i]);
	}
	env[i] = NULL;
	*environ = env;

	return (len);
}

/**
 * doFree - free the env plus any variables after malloc fails
 * @env: the environment array
 * @i: the array index of the failed malloc operation
 */

void doFree(char **env, int i)
{
	int j;

	for (j = 0; j < i; j++)
	{
		free(env[j]);
	}
	free(env);
}
