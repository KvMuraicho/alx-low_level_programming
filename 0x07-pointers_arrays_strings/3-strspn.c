#include"main.h"
/**
 * _strspn - Gets the length of a prefix substring.
 * @s: The main string to be scanned.
 * @accept: The string containing the characters to match.
 *
 * Return: The number of bytes in the initial segment 
 *         of s which consist only of bytes from accept.
 */
unsigned int _strspn(char *s, char *accept)
{
       	unsigned int count = 0;
       	char *start = accept;
       
	while (*s)
       	{
	       	while (*accept)
		{
		       	if (*s == *accept)
			{
			       	count++;
			       	break;
			}
		       	accept++;
		}
	       
		if (!(*accept))
	       	{
		       	break;
		}
	       
		accept = start;
	       	s++;
       	}
       	return count;
}
