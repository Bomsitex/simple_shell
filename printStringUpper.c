#include "main.h"

/**
 * printStringUpper - prints a string with special characters.
 *
 * @s: pointer to the string
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printStringUpper(char *s, int *printCount, char *buff)
{
	char *backslashx = "\\x";
	char *zero = "0";

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
		if (((*s > 0) && (*s < 32)) || (*s >= 127))
		{
			if (_strlen(buff) < (BUFFLEN - 2))
				_strncat(buff, backslashx, 2);
			(*printCount) += 2;
			if (*s < 16)
			{
				if (_strlen(buff) < (BUFFLEN - 1))
					_strncat(buff, zero, 1);
				(*printCount)++;
				printHexUpper(*s, printCount, buff);
			}
			else
			{
				printHexUpper(*s, printCount, buff);

			}
			buffchar(*s, buff);
			(*printCount)++;
			s++;
		}
	}
}

