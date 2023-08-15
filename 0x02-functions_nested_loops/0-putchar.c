#include "main.h"

/**
*main - function prints text as output
*
*Return:return 0
*/
int main(void) {
    char str[] = "_putchar";
    for(int i = 0; str[i] != '\0'; i++) {
        _putchar(str[i]);
    }
    _putchar('\n');

    return 0;
}
