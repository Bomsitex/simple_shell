#include "main.h"

/**
 * printStringReverse - prints a string in reverse.
 *
 * @s: Pointer to the string to print.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printStringReverse(char *s, int *printCount, char *buff)
{
	int i = 0, len;

	/* check for NULL pointer */
	if (s == NULL)
	{
		if (_strlen(buff) < (BUFFLEN - 6))
			_strncat(buff, "(null)", 6);
		(*printCount) += 6;
		return;
	}

	while (s[i] != '\0')
		i++;
	len = i;

	for (i = len - 1; i >= 0; i--)
	{
		buffchar(s[i], buff);
		(*printCount)++;
	}
}

