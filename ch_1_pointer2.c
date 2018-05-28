#include<stdio.h>

int main(){
    char *cptr = (char*)2;
    printf("The value of cptr is %p",cptr);
    cptr++;
    printf("The value of cptr is %p",cptr);

    int *iptr = (int*)2;
    printf("The value of iptr is %p",iptr);
    iptr++;
    printf("The value of iptr is %p",iptr);
}
