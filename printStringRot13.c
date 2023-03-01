#include "main.h"

/**
 * printStringRot13 - prints a string in rot13 format.
 *
 * @s: Pointer to the string to print.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/
void printStringRot13(char *s, int *printCount, char *buff)
{
	/* check for NULL pointer */
	if (s == NULL)
	{
		if (_strlen(buff) < (BUFFLEN - 6))
			_strncat(buff, "(null)", 6);
		(*printCount) += 6;
		return;
	}

	/* get rot13 version of string */
	s = rot13(s);

	while (*s)
	{
		buffchar(*s, buff);
		(*printCount)++;
		s++;
	}
}

