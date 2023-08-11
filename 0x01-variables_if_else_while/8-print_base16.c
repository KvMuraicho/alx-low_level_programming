#include <stdio.h>

/**
 * main - prints all numbers of base 16 in lowercase,
 * followed by a new line.
 * Return: Always 0.
 */
int main(void)
{
	int i;
	char c;
	
	for (i = 0; i < 16; i++)
	
	{
        if (i < 10)
            c = i + '0';
        else
            c = i - 10 + 'a';

        putchar(c);
        if (i != 15)
            putchar('\n');
    }
    putchar('\n');

    return (0);
}

