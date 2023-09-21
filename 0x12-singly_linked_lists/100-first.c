#include <stdio.h>

/**
 * premain - executes before main
 *
 * Description: Prints specific sentences before main execution
 */
void __attribute__((constructor)) premain(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

