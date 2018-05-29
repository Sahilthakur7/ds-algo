#include<stdio.h>

void func(int *a , int *b);
int main(){
    int x = 5;
    int y = 6;

    func(&x,&y);
    printf("The values of x and y after being passed into the func and back in the main are %d and %d\n",x,y);
}

void func(int *a, int *b){
    printf("The values inside a and b are %d and %d\n",*a,*b);

    *a = *a + 8 ;
    *b = *b + 8 ;

    printf("The values after modification in func itself are %d and %d\n",*a,*b);
}
