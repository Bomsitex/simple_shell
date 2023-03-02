#include "main.h"

/**
 * printHexLower - prints hex in lower case
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printHexLower(unsigned int n, int *printCount, char *buff)
{
	unsigned int num = n;

	/*print the first few digits*/
	if ((num / 16) > 0)
	printHexLower(num / 16, printCount, buff);

	/*print the remainders*/
	printHexLowerDigits((num % 16), printCount, buff);

}

