#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 *           
 * @str: string to be duplicated
 *
 * Return: Pointer to the duplicated string or NULL if error
 */
char *_strdup(char *str)
{
    char *duplicate;
    unsigned int i, len = 0;

    if (str == NULL)
        return (NULL);

    while (str[len])
        len++;

    duplicate = (char *)malloc(len + 1);

    if (duplicate == NULL)
        return (NULL);

    for (i = 0; i <= len; i++)
        duplicate[i] = str[i];

    return (duplicate);
}

