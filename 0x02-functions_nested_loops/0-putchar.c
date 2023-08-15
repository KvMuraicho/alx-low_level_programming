/* main.h */
#ifndef MAIN_H
#define MAIN_H

int _putchar(char c);

#endif /* MAIN_H */

/* _putchar.c */
#include <unistd.h>

int _putchar(char c)
{
    return write(1, &c, 1);
}

/* main.c */
#include "main.h"

int main(void) {
    char *str = "_putchar";

    while (*str) {
        _putchar(*str++);
    }
    _putchar('\n');

    return 0;
}

