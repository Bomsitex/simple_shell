#include "main.h"

/**
 * printString - prints a string.
 *
 * @s: Pointer to the string to print.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printString(char *s, int *printCount, char *buff)
{
	/* check for NULL pointer */
	if (s == NULL)
	{
		if (_strlen(buff) < (BUFFLEN - 6))
			_strncat(buff, "(null)", 6);
		(*printCount) += 6;
		return;
	}
	while (*s)
	{
		buffchar(*s, buff);
		(*printCount)++;
		s++;
	}
}

