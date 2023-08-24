#include "main.h"

/**
 * rot13 - encodes a string using rot13
 * @s: The string to encode.
 *
 * Return: The encoded string.
 */
char *rot13(char *s) {
    int i = 0;
    int j;
    char plain[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char cipher[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    while (s[i]) {
        for (j = 0; j < 52; j++) {
            if (s[i] == plain[j]) {
                s[i] = cipher[j];
                break;  
            }
        }
        i++;
    }
    return s;
}

