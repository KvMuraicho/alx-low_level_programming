#include "main.h"
#include <limits.h>

/**
 * _atoi - Convert a string to an integer.
 * @s: The source string.
 *
 * Return: The integer value of the converted string.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, num_started = 0, res = 0;
       
	while (s[i])
{
	if (s[i] == '-')            
		sign = sign * -1;
       
	if (s[i] >= '0' && s[i] <= '9') 
	{
	       	if(res > (INT_MAX - (s[i] - '0')) / 10)
		{
		       	if(sign == 1)
			       	return INT_MAX;
		       	else
			       	return INT_MIN;
		}
	       
		num_started = 1;
	       	res = res * 10 + (s[i] - '0');
       	}
       	else if (num_started)      
	       	break;
       	i++;
}
return sign * res;
}


