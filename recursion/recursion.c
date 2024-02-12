#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int main(int argc, char const *argv[])
{
    if(argc > 1)
    {        
        char *output;
        // parse argument char to int (char to parse, outvar for next item in array after parsed int, number base)
        int num = strtol(argv[1], &output, 10);
        printf("%i! = %i\n", num, factorial(num));
        exit(EXIT_SUCCESS);
    }

    printf("Error: missing argument\n");
    exit(EXIT_FAILURE);
}


int factorial(int x)
{
    if(x > 1)
    {
        return x * factorial(x-1);
    }
    else
    {
        return 1;
    }
}
