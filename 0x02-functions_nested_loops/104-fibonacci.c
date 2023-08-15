#include <stdio.h>
#include <string.h>

/**
 * main - finds and prints the first 98 Fibonacci numbers,
 * starting with 1 and 2
 * followed by a new line
 * Return: ALways 0 (Success)
 */

#define MAX_SIZE 1000  /* this size should be sufficient for our purpose */

/* Function to add two string numbers */
void addStrings(char a[], char b[], char result[])
{
    int carry = 0, i, j, k = 0, x, y, sum;
    char temp[MAX_SIZE];

    /* Start from the end */
    for (i = strlen(a) - 1, j = strlen(b) - 1; i >= 0 || j >= 0 || carry > 0; i--, j--)
    {
        x = (i >= 0) ? a[i] - '0' : 0;
        y = (j >= 0) ? b[j] - '0' : 0;

        sum = x + y + carry;
        carry = sum / 10;

        temp[k++] = (sum % 10) + '0';
    }

    temp[k] = '\0';

    /* The addition result is reversed, so we reverse it back. */
    for (i = 0, j = k - 1; i < j; i++, j--)
    {
        char ch = temp[i];
        temp[i] = temp[j];
        temp[j] = ch;
    }

    strcpy(result, temp);
}

int main(void)
{
    char a[MAX_SIZE] = "1";
    char b[MAX_SIZE] = "2";
    char result[MAX_SIZE];
    int i;

    printf("1, 2");

    for (i = 3; i <= 98; i++)
    {
        addStrings(a, b, result);
        printf(", %s", result);

        strcpy(a, b);
        strcpy(b, result);
    }

    printf("\n");
    return 0;
}

