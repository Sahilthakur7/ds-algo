#include<stdio.h>

int factorial(int num);
int main(){
    int number,result;
    printf("Enter the number you want the factorial of \n");
    scanf("%d",&number);
    result = factorial(number);
    printf("\n The factorial of %d is %d",number,result);
    return 0;
}

int factorial(int num){
    if(num==1){
        return 1;
    }
    else if(num == 0){
        return 1;
    }
    else{
        return num * factorial(num-1);
    }
}
