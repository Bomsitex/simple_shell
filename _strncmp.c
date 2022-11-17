/*****************************************************************************/
#include "main.h"
/**
 * _strncmp - compare n chars from two strings
 *
 * @s1: string 1
 * @s2: string 2
 * @n: number of chars to compare
 *
 * Return: diff between strings +/-/0
 */
int _strncmp(const char *s1, const char *s2, int n)
{
	int i, shorter, s1_sz, s2_sz, sm_sz, ssz;
	/* get the string sizes */
	s1_sz = _strlen(s1);
	s2_sz = _strlen(s2);
	/* Note the shorter string */
	if (s1_sz < s2_sz)
		shorter = 1;
	else if (s1_sz == s2_sz)
		shorter = 0;
	else
		shorter = 2;
	/* note the smaller size */
	sm_sz = (s1_sz <= s2_sz) ? s1_sz : s2_sz;
	/* determine scan size ssz as the smaller of n and sm_sz */
	ssz = (n <= sm_sz) ? n : sm_sz;
	/* scan each byte */
	for (i = 0; i < ssz; i++)
	{
	if (s1[i] < s2[i])
		return (s1[i] - s2[i]);
	else if (s1[i] > s2[i])
		return (s1[i] - s2[i]);
	}
	/* in case of equal scan, use shorter one */
	/* then if ssz is sm_sz then the longer one is greater */
	if (n > sm_sz)
	{
		if (shorter == 1)
			return (-s2[i]);
		else if (shorter == 0)
			return (0);
		else if (shorter == 2)
			return (s1[i]);
	}
	return (0);
}

