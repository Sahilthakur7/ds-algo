#include<stdio.h>

int main(){
    int x = 10;
    int *ptr = &x;
    printf("The value of x is %d \n",x);
    printf("The pointer ptr points to %p \n",ptr);
    printf("There lies the value %d \n",*ptr);
    *ptr = 25;
    printf("Now x contains the value %d",x);
}
