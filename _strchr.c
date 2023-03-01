/*****************************************************************************/
#include "main.h"

/**
 * _strchr - copy n chars to a buffer
 * @s: the dest buffer
 * @c: the character to search
 *
 * Return: the resulting string.
 */
char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i] != c)
	{
		if (s[i] == '\0')
			return ((char *)'\0');
		i++;
	}

	return (s + i);
}
