#include "main.h"

/**
 * printChar - prints a char to buffer.
 *
 * @ch: The char to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/
void printChar(char ch, int *printCount, char *buff)
{
	buffchar(ch, buff);
	(*printCount)++;
}

