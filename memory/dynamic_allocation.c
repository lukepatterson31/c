#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int age;
} person;

int main(){
    // Here we declare a person pointer called myperson
    // (person *) malloc(...) is typecasting the void pointer returned from malloc to a person type pointer
    person * myperson = (person *) malloc(sizeof(person));

    myperson->name = "John";
    myperson->age = 27;

    // Use free() to release the memory used for myperson
    free(myperson);

    // Dynamic memory allocation for arrays
    int n = 5;
    char *pvowels = (char *) malloc(n * sizeof(char));
    int i;

    pvowels[0] = 'A';
    pvowels[1] = 'E';
    *(pvowels + 2) = 'I';
    pvowels[3] = 'O';
    *(pvowels + 4) = 'U';

    for(i = 0; i < n; i++){
        printf("%c ", pvowels[i]);
    }

    printf("\n");

    free(pvowels);

    // Dynamic memory allocation for multidimensional arrays
    int nrows = 2;
    int ncols = 5;
    int j;

    // allocate memory for nrows pointers, size of a char pointer
    char **pvowelsmd = (char **) malloc(nrows * sizeof(char *));

    // allocate memory for each row for ncols elements
    pvowelsmd[0] = (char *) malloc(ncols * sizeof(char));
    pvowelsmd[1] = (char *) malloc(ncols * sizeof(char));

    pvowelsmd[0][0] = 'A';
    pvowelsmd[0][1] = 'E';
    pvowelsmd[0][2] = 'I';
    pvowelsmd[0][3] = 'O';
    pvowelsmd[0][4] = 'U';

    pvowelsmd[1][0] = 'a';
    pvowelsmd[1][1] = 'e';
    pvowelsmd[1][2] = 'i';
    pvowelsmd[1][3] = 'o';
    pvowelsmd[1][4] = 'u';

    for(i = 0; i < nrows; i++){
        for(j = 0; j < ncols; j++){
            printf("%c ", pvowelsmd[i][j]);
        }
    }

    printf("\n");

    free(pvowelsmd[0]);
    free(pvowelsmd[1]);

    free(pvowelsmd);

    return 0;
}