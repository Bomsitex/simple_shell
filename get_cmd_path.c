#include "main.h"

/**
 * getCmdPath - determine and set the absolute path of the command
 *
 * @args: the command vector
 * @pathname: pointer to the pathname string
 * Return: 0 if ok else -1 on error
 */

int getCmdPath(char **args, char *pathname)  /* do not call if args == NULL */
{
	char ch, *path, **pathVector;
	struct stat fileStat; /* will hold the file stat */
	int i = 0;

	path = _strdup(_getenv("PATH"));  /* must free path later */
	pathVector = parseLine(path, ":"); /* free pathVector later */

	/* check if path cmd starts with / or . */
	ch = args[0][0];
	if (ch == '/' || ch == '.')
	{

		_strcpy(pathname, args[0]);   /* use args[0] as pathname */
	}
	/* if given commandname contains a / which is not at the end: */
	else if (_strchr(args[0], '/') && (args[0][_strlen(args[0])] != '/'))
	{
		getcwd(pathname, PATH_MAX);
		_strcat(pathname, "/");
		_strcat(pathname, args[0]);
	}
	else /* do path search */
	{
		/* generate pathname */
		while (pathVector[i])
		{
			_strcpy(pathname, pathVector[i]);
			_strcat(pathname, "/");
			_strcat(pathname, args[0]);
			if (!stat(pathname, &fileStat))
				break;
			i++;
		}
	}
	free(path);
	free(pathVector);
	return (stat(pathname, &fileStat));
}

