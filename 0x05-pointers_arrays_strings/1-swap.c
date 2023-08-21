#include <stdio.h>

/**
 * swap_int - swaps the values of two integers
 * @a: pointer to first value
 * @b: pointer to second value
 */

void swap(int *a, int *b) {
	int temp = *a;  
	*a = *b;       
       	*b = temp;     
}

