#include <stdio.h>

typedef struct
{
    int x;
    int y;
} point;

// Pass a variable, doesn't change the value of n
// outside scope of the function
void addone(int n){
    n++;
}

// Pass a pointer, does change the value of n
// outside the scope of the function
void addonebyref(int *n){
    (*n)++;
}

// Pointers to structures
void move(point *p){
    // Shorthand for (*p).x++
    p->x++;
    p->y++;
}


int main(){
    int a;

    printf("Before: %d\n", a);
    addone(a);
    printf("After addone: %d\n", a);
    addonebyref(&a);
    printf("After addonebyref: %d\n", a);

    point p;

    printf("Before move: x%d,y%d\n", p.x, p.y);
    move(&p);
    printf("After move: x%d,y%d\n", p.x, p.y);

    return 0;
}
