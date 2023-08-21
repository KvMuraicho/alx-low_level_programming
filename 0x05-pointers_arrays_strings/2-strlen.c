#include <stdio.h>

/**
 * _strlen - returns the length of a string
 * @s: string to evaluate
 *
 * Return: the length of the string
 */



int string_length(const char *str) {
	int len = 0;
	while (*str) {
		len++;
		str++;
	}
	return len;
}

