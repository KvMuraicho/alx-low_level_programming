#include <stdio.h>

/**
 * premain - Function to be executed before main
 */
void __attribute__((constructor)) premain()
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}
