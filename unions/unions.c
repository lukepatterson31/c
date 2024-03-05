#include <stdio.h>

// Union to hold and integer and it's bytes
union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

// Struct to hold a number and it's type
// tagged union, the tag (type) indicates which numeric type is stored
struct operator {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    };
};

// Union to hold the counts of different coins
// coins[0] == quarter, etc.
union Coins {
    struct {
        int quarter;
        int dime;
        int nickel;
        int penny;
    };
    int coins[4];
};

int main(){
    union intParts parts;
    parts.theInt = 5968145; // arbitrary number > 255 (1 byte)

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    parts.theInt, parts.bytes[0], parts.bytes[1], parts.bytes[2], parts.bytes[3]);

    // vs pointer arithmetic

    int theInt = parts.theInt;
    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, *((char*)&theInt+0), *((char*)&theInt+1), *((char*)&theInt+2), *((char*)&theInt+3));

    // or with array syntax

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);

    union Coins change;
    for(int i = 0; i < sizeof(change) / sizeof(int); ++i)
    {
        if(scanf("%i", change.coins + i) != 1){
            printf("Invalid input!\n");
            return 1;
        }
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.quarter, change.dime, change.nickel, change.penny);
    
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.coins[0], change.coins[1], change.coins[2], change.coins[3]);

    return 0;
}