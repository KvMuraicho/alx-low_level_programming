#include "main.h"

/**
 * get_endianness - Checks the endianness.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
    unsigned int test = 1;
    char *byte_ptr = (char *)&test;

    return (*byte_ptr);
}