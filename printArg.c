#include "main.h"

int printArg2(va_list ap, char cspec, int *printCount, char *buff);
/**
 * printArg - print the argument
 * @ap: va_list pointer to the arguments
 * @cspec: conversion specifier string
 * @printCount: pointer to the print count
 * @buff: print buffer
 * Return: the number of characters printed but not added to printCount yet
 */
int printArg(va_list ap, char cspec, int *printCount, char *buff)
{
	switch (cspec)
	{
	case 'c':/* char */
		printChar((char) va_arg(ap, int), printCount, buff);
		break;
	case '%':/* % */
		printChar('%', printCount, buff);
		break;
	case 'd':/* int */
		printInt(va_arg(ap, int), printCount, buff);
		break;
	case 'o':/* Octal */
		printUnsignedOctal(va_arg(ap, unsigned int), printCount, buff);
		break;
	case 'x':/* HexLower */
		printHexLower(va_arg(ap, unsigned int), printCount, buff);
	}

	/* process the balance */
	printArg2(ap, cspec, printCount, buff);
	return (0);
}


#include "main.h"

/**
 * printArg2 - print the argument
 * @ap: va_list pointer to the arguments
 * @cspec: conversion specifier string
 * @printCount: pointer to the print count
 * @buff: print buffer
 * Return: the number of characters printed but not added to printCount yet
 */
int printArg2(va_list ap, char cspec, int *printCount, char *buff)
{
	switch (cspec)
	{
	case 'X':/* HexUpper*/
		printHexUpper(va_arg(ap, unsigned int), printCount, buff);
	break;
	case 'p':/* HexLower */
		buffchar('0', buff);
		buffchar('x', buff);
		(*printCount) += 2;
		printPointer(va_arg(ap, unsigned long int), printCount, buff);
		break;
	case 'i':/* int */
		printInt(va_arg(ap, int), printCount, buff);
	break;
	case 'u':/* uint */
		printUnsignedInt(va_arg(ap, unsigned int), printCount, buff);
	break;
	case 's':/* string */
		printString(va_arg(ap, char *), printCount, buff);
	break;
	case 'b':/* binary */
		printBinary(va_arg(ap, unsigned int), printCount, buff);
	break;
	case 'S':/* string in upper case*/
		printStringUpper(va_arg(ap, char *), printCount, buff);
	break;
	case 'r':/* string in reverse*/
		printStringReverse(va_arg(ap, char *), printCount, buff);
	break;
	case 'R':/* string in Rot13 format*/
		printStringRot13(va_arg(ap, char *), printCount, buff);
	}
	return (0);
}

