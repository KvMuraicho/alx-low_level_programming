#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - program that generates random valid
 * passwords for the program 101-crackme
 *
 * Return: Always 0 (Success)
 */

int main(void)
{
    char characters[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    int i;
    
    srand(time(NULL));

    for (i = 0; i < PASSWORD_LENGTH; i++)
    {
        printf("%c", characters[rand() % (sizeof(characters) - 1)]);
    }
    printf("\n");

    return (0);
}

