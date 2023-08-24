#include "main.h"
#include <stdio.h>

/**
 * print_buffer - prints a buffer.
 * @b: the buffer.
 * @size: the size of the buffer.
 * Return: Nothing.
 */
void print_buffer(char *b, int size)
{
    int i, j;

    if (size <= 0)
    {
        printf("\n");
        return;
    }

    for (i = 0; i < size; i += 10)
    {
        printf("%08x: ", i);
        for (j = 0; j < 10; j++)
        {
            if (j % 2 == 0 && j != 0)
                printf(" ");

            if (i + j < size)
                printf("%02x", b[i + j]);
            else
                printf("  ");
        }
        printf(" ");
        for (j = 0; j < 10; j++)
        {
            if (i + j < size && (b[i + j] > 31 && b[i + j] < 127))
                printf("%c", b[i + j]);
            else if (i + j < size)
                printf(".");
        }
        printf("\n");
    }
}

