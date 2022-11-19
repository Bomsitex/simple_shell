#include "main.h"

/**
 * printPointer - prints a pointerr.
 *
 * @n: The pointer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printPointer(unsigned long int n, int *printCount, char *buff)
{
	unsigned long int num = n;

	/*print the first few digits*/
	if ((num / 16) > 0)
		printPointer(num / 16, printCount, buff);

	/*print the remainders */
	printPointerDigits((num % 16), printCount, buff);
}

