#include "main.h"

void printPointerDigits2(int n, char *buff);

/**
 * printPointerDigits - prints the hex digits for a pointer.
 *
 * @n: The hex to be printed.
 * @printCount: the count of printed characters
 * @buff: the print buffer
*/
void printPointerDigits(int n, int *printCount, char *buff)
{
	switch (n)
	{
	case 0:
		buffchar('0', buff);
	break;
	case 1:
		buffchar('1', buff);
	break;
	case 2:
		buffchar('2', buff);
	break;
	case 3:
		buffchar('3', buff);
	break;
	case 4:
		buffchar('4', buff);
	break;
	case 5:
		buffchar('5', buff);
	break;
	case 6:
		buffchar('6', buff);
	}

	/* now do the eremainder */
	printPointerDigits2(n, buff);

	if (n >= 0 && n <= 9)
	{
		(*printCount)++;
	}
	else if (n >= 10 && n <= 15)
	{
		(*printCount) += 2;
	}
}



/**
 * printPointerDigits2 - prints the hex digits for a pointer.
 *
 * @n: The hex to be printed.
 * @buff: the print buffer
*/
void printPointerDigits2(int n, char *buff)
{
	switch (n)
	{
	case 7:
		buffchar('7', buff);
	break;
	case 8:
		buffchar('8', buff);
	break;
	case 9:
		buffchar('9', buff);
	break;
	case 10:
		buffchar('a', buff);
	break;
	case 11:
		buffchar('b', buff);
	break;
	case 12:
		buffchar('c', buff);
	break;
	case 13:
		buffchar('d', buff);
	break;
	case 14:
		buffchar('e', buff);
	break;
	case 15:
		buffchar('f', buff);
	}
}

