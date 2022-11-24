#include "main.h"

void _unsetValue(char **env);

/**
 * _unsetenv - unssets an environment variable in the environment
 *
 * @name: the environment variable to unset
 * Return: 0 on success, -1 on error
 */
int _unsetenv(const char *name)
{
	/* int unsetenv(const char *name); */
	int i = 0, len, unset = 0;

	if (name == NULL || _strchr("name", '=') || _strlen(name) == 0)
	{
		errno = EINVAL;
		return (-1);
	}

	while (environ[i])
	{
		if (!_strncmp(name, environ[i], _strlen(name)))
		{
			int k;

			free(environ[i]);
			environ[i] = environ[i + 1];
			for (k = i; environ[k] != NULL; k++)
			{
				environ[k] = environ[k + 1];
			}
			/*_unsetValue(&(environ[i]));  */
			unset = 1;
		}
		i++;
	}
	len = i;

	if (unset == 1)
	{
		/* void *realloc(void *ptr, size_t size); */
		environ = realloc(environ, sizeof(char *) * (len + 1));
		if (environ == NULL)
		{
			perror("_unsetenv");
			exit(EXIT_FAILURE);
		}
	}

	return (0);
}


/**
 * _unsetValue - unset the name=value pair
 * @env: the environment array starting at the record to un set
 */
void _unsetValue(char **env)
{
	int k = 0;

	/* from unset point, let each environ[k] = environ[[k+1] */
	free(env[k]);  /* free the env variable to unset */
	while (env[k])
	{
		env[k] = env[k + 1];
		k++;
	}
}
