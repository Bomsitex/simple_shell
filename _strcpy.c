/*****************************************************************************/
#include "main.h"

/**
 * _strcpy - prints an array of n integers
 * @src: the string to copy
 * @dest: the destination buffer
 * Return: pointer to dest
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

