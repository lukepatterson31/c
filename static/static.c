#include <stdio.h>

int runner() {
    // Declaring a variable as static increases it's scope to the file containing it
    // Any changes will persist within the scope of this file
    static int count = 0;
    count++;
    return count;
}

static void fun(void){
    // Declaring a function as static reduces it's scope to the file containing it, as functions are global by default
    printf("I'm a static function.\n");
}

int main(){
    printf("%d ", runner());
    printf("%d ", runner());
    return 0;
}