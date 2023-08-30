#include"main.h"
/**
 * _sqrt_check - Checks for the square root.
 * @n: The number to find the square root of.
 * @i: The current divisor to check.
 * 
 * Return: The square root if found, -1 otherwise.
 */
int _sqrt_check(int n, int i)
{
       	if (i * i == n)
	{
		return (i);
	}
	if (i * i > n)
	{
	       	return (-1);
	}
       	return _sqrt_check(n, i + 1);
}
/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The number to find the square root of.
 *
 * Return: The square root if exists, -1 otherwise.
 */
int _sqrt_recursion(int n)
{
       	if (n < 0)
	{
		return (-1);
	}
       	return _sqrt_check(n, 1);
}

