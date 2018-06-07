#include<stdio.h>

char array[5];
void binary(int n);

int main(){
    int n;

    printf("Enter the length of the n bit string:");
    scanf("%d",&n);

    binary(n);

    return 0;
}

void binary(int n){
    if(n<1){
        printf("%s\n",array);
    }
    else{
        array[n-1]= '0';
        binary(n-1);
        array[n-1]= '1';
        binary(n-1);
    }
}
