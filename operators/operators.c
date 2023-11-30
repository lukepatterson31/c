#include <stdio.h>

int main(){
    int x = 5;
    int y = 3;
    printf("***Boolean Operators***\n\n");
    printf("x is %d and y is %d\n\n", x, y);
    printf("true is 1, false is 0\n\n");
    printf("x > y (true == 1): %d\n", x > y);
    printf("x < y (true == 1): %d\n", x < y);
    printf("x >= y (true == 1): %d\n", x >= y);
    printf("x <= y (true == 1): %d\n", x <= y);
    printf("x == y (true == 1): %d\n\n", x == y);

    printf("***Sizeof Operator***\n\n");
    // Use %lu (long unsigned int) instead of %d (int)
    printf("Sizeof x: %lu\n", sizeof(x));
    printf("Sizeof y: %lu\n\n", sizeof(y));

    printf("***Bitwise Operators***\n\n");

    int xShiftLeftOne = x << 1;
    int xShiftLeftTwo = x << 2;
    int xShiftLeftThree = x << 3;
    
    int xShiftRightOne = x >> 1;
    int xShiftRightTwo = x >> 2;
    int xShiftRightThree = x >> 3;

    printf("x is set to: %d\n\n", x);
    printf("Shift left one: %d\nShift left two: %d\nShift left three: %d\n\n", xShiftLeftOne, xShiftLeftTwo, xShiftLeftThree);
    printf("Shift right one: %d\nShift right two: %d\nShift right three: %d\n\n", xShiftRightOne, xShiftRightTwo, xShiftRightThree);
    return 0;
}