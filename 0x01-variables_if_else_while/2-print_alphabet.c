/*
 * File: 2-print_alphabet.c
 * Auth: Kelly V Muraicho
 */
#include <stdio.h>

int main(void)
{
    char letter;

    for (letter = 'a'; letter <= 'z'; letter++)
    {
        putchar(letter);
    }
    putchar('\n');

    return (0);
}
