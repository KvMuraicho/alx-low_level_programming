#include "main.h"
#include <stdio.h>

char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int a_len = 0, b_len = 0, carry = 0, a, b, sum, biggest;
	
	while (n1[a_len] != '\0')
		a_len++;
	while (n2[b_len] != '\0')
		b_len++;
	if (a_len > b_len)
		biggest = a_len;
	else
		biggest = b_len;

	if ((biggest + 2) > size_r) 
		return (0);
	r[biggest + 1] = '\0';

	a_len--;
	b_len--;

	while (biggest >= 0)
	{
		a = (a_len >= 0) ? (n1[a_len] - '0') : 0;  
		b = (b_len >= 0) ? (n2[b_len] - '0') : 0;  

		sum = a + b + carry;

		if (sum > 9)
		{
			carry = sum / 10;
			sum = (sum % 10) + '0';
		}
		else
		{
			carry = 0;
			sum = sum + '0';
		}
		r[biggest] = sum;
		a_len--;
		b_len--;
		biggest--;
	}

	if (carry)  
		return (0);

	if (*(r) != '0') 
		return (r);
	else
		return (r + 1);
}

