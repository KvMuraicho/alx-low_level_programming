#include "main.h"

/**
 * print_second_half - Outputs the latter half of a string
 * @s: The string to be processed
 */
void print_second_half(char *s)
{
    int length = 0;
    int start;

    
    while (s[length] != '\0')
    {
        length++;
    }

   
    start = (length % 2 == 0) ? length / 2 : (length + 1) / 2;

 
    for (int i = start; s[i] != '\0'; i++)
    {
        _putchar(s[i]);
    }

    _putchar('\n');
}

