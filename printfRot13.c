/**
 * rot13 - encode a string in rot13
 *
 * @str: the string to encode
 *
 * Return: the resulting string
 */
char *rot13(char *str)
{
	int i, j;
	char src[] =	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char target[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; src[j] != '\0'; j++)
		{
			if (str[i] == src[j])
			{
				str[i] = target[j];
				break;
			}
		}
	}
	return (str);
}

