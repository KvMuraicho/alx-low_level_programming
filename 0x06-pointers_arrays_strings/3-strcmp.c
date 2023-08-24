#include "main.h"
/**
 * _strcmp - Compares two strings.
 * @s1: First string.
 * @s2: Second string.
 * Return: Difference of the ASCII values of the first differing character, 
 *         or 0 if the strings are identical.
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
	       	s2++;
	}
       	return (*s1 - *s2);
}

