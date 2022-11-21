#include "main.h"

/**
 * main - a simple UNIX shell (sh) with basic features
 * @argc: number of command line arguments
 * @argv: arguments vector
 * Return: 0 on sucess, -1 on error
 */
int main(int argc, char *argv[])
{
	int lastError = 0;

	if (argc == 1)
		lastError = ssInteractive(argc, argv);
	else
		lastError = ssBatch(argc, argv);

	return (lastError);
}
