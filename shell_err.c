#include "main.h"

/**
 * shellErr - orderly way to handle errors upon exit
 *
 * @code: error code
 */
void shellErr(int code)
{
	switch (code)
	{
		case 1:
			exit(EXIT_FAILURE);
			break;
		case 2:
			exit(EXIT_SUCCESS);
	}
}

