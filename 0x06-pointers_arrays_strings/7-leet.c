#include "main.h"

/**
 * leet - encodes a string into 1337
 * @s: The string to encode.
 *
 * Return: The encoded string.
 */
char *leet(char *s) {
    char original[] = "aAeEoOtTlL";
    char replacement[] = "4300711701";
    int i = 0, j;

    while (s[i]) {
        for (j = 0; original[j]; j++) {
            if (s[i] == original[j]) {
                s[i] = replacement[j];
                break; 
            }
        }
        i++;
    }
    return s;
}

