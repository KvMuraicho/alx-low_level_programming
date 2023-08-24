#include "main.h"

/**
 * _strncat - Concatenate two strings using at most n bytes from src.
 * @dest: Destination string.
 * @src: Source string.
 * @n: Maximum number of bytes to be concatenated.
 * Return: Pointer to the resulting string dest.
 */
char *_strncat(char *dest, char *src, int n)
{
	int destIndex = 0, srcIndex = 0;
	
	while (dest[destIndex] != '\0')
		destIndex++;
	
	while (srcIndex < n && src[srcIndex] != '\0')
	
	{
	       	dest[destIndex] = src[srcIndex];
	       	destIndex++;
	       	srcIndex++;
	}
       
	dest[destIndex] = '\0';
       	return dest;
}

