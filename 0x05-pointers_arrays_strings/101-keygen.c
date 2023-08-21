#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    int pass[100];
    int i, sum = 0, n;
    srand(time(NULL));

    for (i = 0; i < 100; i++)
    {
        pass[i] = rand() % 78;  // Generate a random value between 0 and 77
        sum += pass[i];  // Keep a running total of the sum
        
        if (2772 - sum < 78)
        {
            n = 2772 - sum;
            sum += n;
            putchar(n + '0');
            break;
        }
        
        putchar(pass[i] + '0');  // Print the current character
    }
    return (0);
}

