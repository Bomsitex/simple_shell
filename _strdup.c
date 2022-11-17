/*****************************************************************************/
#include <stdlib.h>
#include "main.h"
/**
 * _strdup - create a copy of a string
 *
 * @str: the str to copy
 * Return: the string created
 */
char *_strdup(const char *str)
{
	unsigned int i, len = 0;
	char *buf;

	if (str == NULL)
		return (NULL);

	/* determine string size */
	while (str[len])
		len++;

	buf = (char *)malloc((len + 1) * sizeof(char));

	if (!buf)
	{
		return (NULL);
	}
	else
	{
		for (i = 0; i < len; i++)
			buf[i] = str[i];
	}
		buf[len] = '\0';

	return (buf);

}

