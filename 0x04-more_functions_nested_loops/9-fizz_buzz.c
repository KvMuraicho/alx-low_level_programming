
#include "main.h"

/**
 * main - prints the numbers from 1 to 100, followed by a new line.
 * Return: Always 0.
 i*/
int main(void)
{
int i = 1;
while (i <= 100)
{
if (i % 3 == 0 && i % 5 == 0)
{
printf("FizzBuzz ");
}
else if (i % 3 == 0)
{
printf("Fizz ");
}
else if (i % 5 == 0)
{
if (i == 100)
{
printf("Buzz");
}
else if (i != 100)
{
printf("Buzz ");
}
}
else
{
printf("%d ", i);
}
i++;
}
printf("\n");
return (0);
}
