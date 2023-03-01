/*****************************************************************************/
#include "main.h"
/**
 * _strcat - concatenates two strings
 * uses _putchar()
 *
 * @dest: the destination string
 * @src: the src string
 *
 * Return: the length of the string
 */
char *_strcat(char *dest, char *src)
{
	int i, dest_sz, src_sz;

	dest_sz = _strlen(dest);
	src_sz = _strlen(src);

	for (i = 0; i <= src_sz; i++)
	{
		dest[dest_sz + i] = src[i];
	}

	return (dest);
}

