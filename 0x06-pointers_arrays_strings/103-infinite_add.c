#include "main.h"
#include <stdio.h>
/**
 * infinite_add - add 2 strings.
 * @n1: string1.
 * @n2: string2.
 * @r: buffer
 * @size_r: buffer size
 * Return: String with all letters in ROT13 base.
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
    int len1, len2, k, carry = 0, sum;

    for (len1 = 0; n1[len1] != '\0'; len1++)
        ;
    for (len2 = 0; n2[len2] != '\0'; len2++)
        ;

    if (size_r <= len1 + 2 || size_r <= len2 + 2)
        return (0);

    len1--;
    len2--;
    k = 0;

    while (len1 >= 0 || len2 >= 0 || carry != 0)
    {
        if (len1 >= 0)
            carry += n1[len1] - '0';
        if (len2 >= 0)
            carry += n2[len2] - '0';

        if (k >= size_r - 1)
            return (0);

        r[k] = (carry % 10) + '0';
        carry /= 10;
        k++;
        len1--;
        len2--;
    }

    r[k] = '\0';

 
    for (int i = 0; i < k / 2; i++)
    {
        char tmp = r[i];
        r[i] = r[k - 1 - i];
        r[k - 1 - i] = tmp;
    }

    return (r);
}

