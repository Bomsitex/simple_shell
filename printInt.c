#include "main.h"

/**
 * printInt - prints an integer.
 *
 * @n: The integer to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/

void printInt(int n, int *printCount, char *buff)
{
	unsigned int num = n;

	/*first check if its negative*/
	if (n < 0)
	{
		buffchar('-', buff);/* change later */
		num = -num;
	}

	/*print the first few digits*/
	if ((num / 10) > 0)
	printInt(num / 10, printCount, buff);

	/*print the last digit*/
	buffchar((num % 10) + 48, buff);
	(*printCount)++;
}


