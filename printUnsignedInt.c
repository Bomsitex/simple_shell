#include "main.h"

/**
 * printUnsignedInt - prints an unsigned integer.
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/


void printUnsignedInt(unsigned int n, int *printCount, char *buff)
{
	unsigned int num = n;

	/*print the first few digits*/
	if ((num / 10) > 0)
	printUnsignedInt(num / 10, printCount, buff);

	/*print the last digit*/
	buffchar((num % 10) + 48, buff);
	(*printCount)++;
}

