#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: string to which the concatenation is added
 * @src: string to be concatenated to dest
 * Return: Pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
	int lengthD = 0;
	int lengthS = 0;
	
	while (dest[lengthD] != '\0')
		lengthD++;
	
	while (src[lengthS] != '\0' && lengthD < 97)
	{
		dest[lengthD] = src[lengthS];
		lengthD++;
		lengthS++;
	}
	dest[lengthD] = '\0';
	
	return dest;
}
