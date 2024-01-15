#include <stdio.h>

int main(){
    char c = 'A';
    char *pc = &c;

    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    char *pvowels = &vowels;
    int i;

    // print the addresses
    for(i = 0; i < 5; i++){
        printf("&vowels[%d]: %p, pvowels + %d: %p, vowels + %d: %p\n", i, &vowels[i], i, pvowels + i, i, vowels + i);
    }

    // print the values
    for(i = 0; i < 5; i++){
        printf("vowels[%d]: %c, *(pvowels + %d): %c, *(vowels + %d): %c\n", i, vowels[i], i, *(pvowels + i), i, *(vowels + i));
    }

    return 0;
}