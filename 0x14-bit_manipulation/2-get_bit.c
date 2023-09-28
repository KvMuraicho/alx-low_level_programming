#include "main.h"

void print_bits(unsigned long int n);

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
	{
		_putchar('0');
		return;
	}
	print_bits(n);
}

/**
 * print_bits - Recursively prints the binary representation of a number.
 * @n: The number.
 */
void print_bits(unsigned long int n)
{
	if (n == 0)
	{
		return;
	}
	print_bits(n >> 1);
	_putchar((n & 1) + '0');
}
