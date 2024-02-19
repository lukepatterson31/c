#include <stdio.h>

union intParts {
    int theInt;
    char bytes[sizeof(int)];
};

// tagged union
struct operator {
    int type;
    union {
        int intNum;
        float floatNum;
        double doubleNum;
    };
};

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

    // or with array syntax which can be a tiny bit nicer sometimes

    printf("The int is %i\nThe bytes are [%i, %i, %i, %i]\n",
    theInt, ((char*)&theInt)[0], ((char*)&theInt)[1], ((char*)&theInt)[2], ((char*)&theInt)[3]);

    union Coins change;
    for(int i = 0; i < sizeof(change) / sizeof(int); ++i)
    {
        scanf("%i", change.coins + i); // BAD code! input is always suspect!
    }
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.quarter, change.dime, change.nickel, change.penny);
    
    printf("There are %i quarters, %i dimes, %i nickels, and %i pennies\n",
    change.coins[0], change.coins[1], change.coins[2], change.coins[3]);

    return 0;
}