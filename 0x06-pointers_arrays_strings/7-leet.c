#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: The string to encode.
 *
 * Return: The encoded string.
 */
char *leet(char *s) {
       	int i, j;
       	char letters[] = "aAeEoOtTlL";
       	char numbers[] = "43007110";
       
	for (i = 0; s[i]; i++) {
	       	for (j = 0; letters[j]; j++) {
		       	if (s[i] == letters[j]) {
			       	s[i] = numbers[j / 2];
			       	break;
		       	}
	       	}
       	}
       	return s;
}
