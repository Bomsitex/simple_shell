#include "main.h"

#define plBUFFUNIT 8
#define plBUFFCAP 16

void parseMallocCheck(char **tokens, int *jobNr);
/**
 * parseLine - parse string into tokens based on given delimiters
 * @str: the string to parse
 * @delim: the string of delimiters
 * @jobNr: the sequence number of the current commands job
 * Return: pointer to the vector of tokens
 */
char **parseLine(char *str, char *delim, int *jobNr)
{
	char *ptr = str;
	char **tokens;
	size_t buffcap = plBUFFCAP, i = 0;

	(void) jobNr;
	tokens = malloc(sizeof(char *) * buffcap);
	parseMallocCheck(tokens, jobNr);
	tokens[0] = NULL;
	while (*ptr)
	{
		while (*ptr)
		{
			if (!_strchr(delim, *ptr))
			{
				tokens[i] = ptr;
				tokens[i + 1] = NULL;
				break;
			}
			*ptr = '\0';
			ptr++;
		}
		while (*ptr)
		{
			if (_strchr(delim, *ptr))
				break;
			ptr++;
		}
		i++;
		if (i == buffcap)
		{
			buffcap += plBUFFUNIT;
			tokens = realloc((void *) tokens,
				sizeof(char *) * buffcap);
			parseMallocCheck(tokens, jobNr);
		}
	}
	tokens = realloc((void *) tokens, sizeof(char *) * (i + 1));
	parseMallocCheck(tokens, jobNr);
	return (tokens);
}

/**
 * parseMallocCheck - error check memory allocation
 *
 * @jobNr: the sequence number of the current commands job
 * @tokens: the double poiter allocated by malloc or realloc
 */
void parseMallocCheck(char **tokens, int *jobNr)
{
	if (!tokens)
	{
		_printf("%d: ", *jobNr);
		perror("parseLine: Memory Allocation Failure");
		exit(EXIT_FAILURE);
	}
}
