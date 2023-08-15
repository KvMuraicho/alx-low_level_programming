#include <stdio.h>

/**
 * main - finds and prints the sum of the even-valued terms
 * followed by a new line
 * Return: Always 0 (Success)
 */

int main(void)
{
    unsigned long a = 1, b = 2, next, sum = 2;  /* We initialize sum to 2 because the second Fibonacci term is 2 and even. */

    while (1)
    {
        next = a + b;

        if (next > 4000000)  /* If the next Fibonacci number exceeds 4,000,000, break out of the loop. */
            break;

        if (next % 2 == 0)  /* If the Fibonacci number is even, add to sum. */
            sum += next;

        /* Move to the next Fibonacci terms. */
        a = b;
        b = next;
    }

    printf("%lu\n", sum);  /* Print the sum. */
    return 0;
}

