#include "main.h"

/**
 * printUnsignedOctal - prints an unsigned Octal integer.
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/
void printUnsignedOctal(unsigned int n, int *printCount, char *buff)
{
	unsigned int num = n;

	/*print the first few digits*/
	if ((num / 8) > 0)
	printUnsignedOctal(num / 8, printCount, buff);

	/*print the remainders*/
	buffchar((num % 8) + 48, buff);
	(*printCount)++;
}

