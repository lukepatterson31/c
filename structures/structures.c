#include <stdio.h>

struct point {
    int x;
    int y;
};

// Use Typedefs to avoid using struct everytime we define a new point
typedef struct{
    int x;
    int y;
} point;

// Use structures to hold pointers to strings or other structures
typedef struct {
    // char pointer for a string
    char * brand;
    int model;
} vehicle;


int main(){
    struct point p;
    p.x = 10;
    p.y = 20;

    point pi;
    pi.x = 12;
    pi.y = 24;

    vehicle mycar;
    mycar.brand = "Toyota";
    mycar.model = 2003;

    return 0;
}