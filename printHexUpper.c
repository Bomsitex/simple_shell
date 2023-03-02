#include "main.h"

/**
 * printHexUpper - prints a hex in lower case.
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printHexUpper(unsigned int n, int *printCount, char *buff)
{
	unsigned int num = n;

	if ((num / 16) > 0)
	printHexUpper(num / 16, printCount, buff);

	/*print the remainders*/
	printHexUpperDigits((num % 16), printCount, buff);

}

