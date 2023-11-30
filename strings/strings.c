#include <stdio.h>
#include <string.h>

int main() {
    // Creates a pointer to a character array
    // This string can only be read
    char * namePointer = "John Smith";

    // This allocates an array variable
    // This string can be manipulated
    // The empty brackets notation [] tells the compiler to calculate the size of the array automatically
    char nameArray[] = "John Smith";

    // This is the same as above, we add one to the length of the string for the string termination character
    // This indicates the end of the string, because the program does not know the length of the string - only the compiler knows it according to the code
    char nameExplicitArray[11] = "John Smith";

    // String formatting with printf()
    int age = 27;
    printf("%s is %d years old.\n", namePointer, age);

    // String length with strlen()
    printf("namePointer is %lu characters long.\n", strlen(namePointer));
    
    // String comparison with strcmp() (unsafe!) and strncmp(string1, string2, stringLen)
    if (strncmp(namePointer, "John Smith", 10) == 0) {
        printf("Hello, John Smith!\n");
    }
    else {
        printf("You're not John. Go away!\n");
    }

    // String concatenation with strncat(string1, string2, numberOfCharsToAdd)
    char dest[20] = "Hello";
    char src[20] = "World";
    strncat(dest, src, 3);
    printf("%s\n", dest);
    strncat(dest, src, 20);
    printf("%s\n", dest);
}