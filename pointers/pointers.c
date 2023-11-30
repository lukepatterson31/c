#include <stdio.h>

int main(){
    int n = 0;
    int * pointer_to_n = &n;
    printf("%d is the value of n\n", n);
    printf("%d is the value of n accessed with a pointer\n", *pointer_to_n);

    n++;
    printf("%d is the updated value of n\n", n);

    *pointer_to_n += 1;
    printf("%d is the updated value of n accessed with a pointer\n", *pointer_to_n);

    // Using *pointer_to_n++ will increase the value of pointer_to_n instead of n, because the ++ operator is evaluated before dereferencing the pointer
    (*pointer_to_n)++;
    printf("%d is the updated value of n accessed with a pointer using (*pointer_to_n)++\n", *pointer_to_n);
}
