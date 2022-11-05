/*****************************************************************************/
#include "main.h"
/**
 * _strlen - returns the length of a string
 * uses _putchar()
 *
 * @s: the string
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int i = 0;

	while (*s != '\0')
	{
		s++;
		i++;
	}
	return (i);
}

