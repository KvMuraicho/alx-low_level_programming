/*
 * File: 4-print_alphabt.c
 *  
 */

#include <stdio.h>

/**
 * main - Prints the alphabet in lowercase, except for q and e.
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
