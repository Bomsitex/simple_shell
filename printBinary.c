#include "main.h"

/**
 * printBinary - prints an integer in binary.
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printBinary(unsigned int n, int *printCount, char *buff)
{
	unsigned int num = n;

	/*print the first few digits*/
	if ((num / 2) > 0)
	printBinary(num / 2, printCount, buff);

	/*print the remainders*/
	buffchar((num % 2) + 48, buff);
	(*printCount)++;
}


