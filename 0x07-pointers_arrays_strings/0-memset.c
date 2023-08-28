#include "main.h"
/**
 * main - check and demonstrate the functionality of _memset function
 * @void: No input parameters
 *
 * Return: Always 0.
 */

char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;
       
	for (i = 0; i < n; i++)
       {
	       s[i] = b;
       }
       
	return s;
}

