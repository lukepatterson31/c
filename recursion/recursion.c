#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int main(int argc, char const *argv[])
{
    if(argc > 1)
    {
        // next char in array after parsed int
        char *output;
        // parse argument to int (string or char to parse, next array item, base)
        int num = strtol(argv[1], &output, 10);
        int x = factorial(num);
        printf("%i! = %i\n", num, x);
        exit(EXIT_SUCCESS);
    }
    printf("Error: missing argument\n");
    exit(EXIT_FAILURE);
}


int factorial(int x){
    if(x > 1)
    {
        return x * factorial(x-1);
    }
    else
    {
        return 1;
    }
}
