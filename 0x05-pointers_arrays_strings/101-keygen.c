#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10

char generate_random_char() {
    const char valid_characters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    return valid_characters[rand() % (sizeof(valid_characters) - 1)];
}

int main(void) {
    char password[PASSWORD_LENGTH + 1];
    int i;

    srand(time(NULL));  

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generate_random_char();
    }
    password[PASSWORD_LENGTH] = '\0'; 

    printf("%s\n", password);
    return 0;
}

