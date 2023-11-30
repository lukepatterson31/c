#include <stdio.h>

int main()
{
    int x = 10;
    int y = 20;
    int num = 5;
    int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if(x > y){
        printf("X is greater than Y!\n");
    }
    else if(x == y){
        printf("X and Y are equal!\n");
    }
    else{
        printf("Y is greater than X!\n");
    }

    for(int i = 0; i < 10; i++){
        if(nums[i] > num){
            printf("Num: %d is greater than Num: %d!\n", nums[i], num);
        }
        else if(nums[i] == num){
            printf("Num: %d and Num: %d are equal!\n", nums[i], num);
        }
        else{
            printf("Num: %d is greater than Num: %d!\n", num, nums[i]);
        }
    }

    return 0;
}

