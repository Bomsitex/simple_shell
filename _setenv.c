#include "main.h"

char *_setValue(char *env, const char *name, const char *value);

/**
 * _setenv - sets an environment variable in the environment
 *
 * @name: the environment variable to set
 * @overwrite: flag to overwrite the variable or not
 * @value: the value string of the environment name=value variable
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	/* setenv VARIABLE VALUE */
	int i = 0;

	if (name == NULL || _strchr("name", '=') || _strlen(name) == 0)
	{
		errno = EINVAL;
		return (-1);
	}

	while (environ[i])
	{
		if (!_strncmp(name, environ[i], _strlen(name)))
		{
			if (overwrite)
				environ[i] = _setValue(environ[i], name, value);
			return (0);
		}
		i++;
	}
	/* void *realloc(void *ptr, size_t size); */
	environ = realloc(environ, sizeof(char *) * (i + 2));
	if (environ == NULL)
	{
		perror("_setenv");
		exit(EXIT_FAILURE);
	}
	environ[i + 1] = NULL;
	environ[i] = _setValue(environ[i], name, value);

	return (0); /* variable not found */
}


/**
 * _setValue - set the name=value pair
 * @name: the env name
 * @value: the env value
 * @env: the environment record to set
 * Return: pointer to the environment record created
 */
char *_setValue(char *env, const char *name, const char *value)
{
	env = realloc(env, sizeof(name) + sizeof(value) + 2);  /* debug */
	if (env == NULL)
	{
		perror("_setenv");
		exit(EXIT_FAILURE);
	}
	_strcpy(env, name);
	_strcat(env, "=");
	_strcat(env, value);

	return (env);
}
