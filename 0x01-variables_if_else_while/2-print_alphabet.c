/**
 * main - Prints the alphabet in lowercase.
 *
 * Return: Always 0.
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
