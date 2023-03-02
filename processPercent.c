#include "main.h"

/**
 * processPercent - process the case of % found
 * @format: the format specifier string
 * @fpos: the format string pointer position
 * @ap: pointer to the args list
 * @printCount: counter for how many characters printed
 * @buff: the 1024 char buffer for speedy printing
 * Return: pointer to the format string in new position
 */
const char *processPercent(const char *format,
		int *fpos, va_list ap, int *printCount, char *buff)
{
	int k;
	char *conv = "csdibuoxXSprR%";

	/* format spec found */
	/*if next item not a conversion specifier then print this % and continue */
	if (!_strchr(conv, *(format + 1)))
	{
		buffchar(*format, buff);

		(*printCount)++;
		return (format);
	}

	{
	/* skip ahead until you find conv */
	k = 1;
	while (!_strchr(conv, *(format + k)))
	{
		/* consider storing format */
		/* chars in a struct here */
		k++;
		(*fpos)++;
	}
		*printCount += printArg(ap, *(format + k), printCount, buff);
		format += k; /* skip format code */
	}

	return (format);
}

