#include <stdio.h>
/**
 * main - prints all single digit numbers of base 10 starting from 0, followed by a new line.
 *
 * Return: Always 0.
 */
int main(void)
{
	char num;
    
    for (num = '0'; num <= '9'; num++)
    {
	    putchar(num);
    }
    putchar('\n');
    
    return (0);
}

