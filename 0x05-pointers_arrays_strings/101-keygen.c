#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 10  

int main(void) {
    int i;
    char password[PASSWORD_LENGTH + 1];  

    srand(time(NULL));  

    for (i = 0; i < PASSWORD_LENGTH; i++) {
        
       
        password[i] = (rand() % (126 - 33 + 1)) + 33;
    }

    password[PASSWORD_LENGTH] = '\0';  
    printf("%s\n", password);

    return 0;
}

