#include<stdio.h>
#include<stdlib.h>

int findmax(int array[],int start, int end);

int main(){
    int max,size,winsize,i;
    int *array;

    printf("Enter the size of the array:");
    scanf("%d",&size);

    array = (int *)malloc(sizeof(int) * size);

    printf("\nEnter the elements in the array:");
    for(i=0;i<size;i++){
        scanf("%d",&array[i]);
    }

    printf("\nYour array is: ");
    for(i=0;i<size;i++){
        printf("%d\t",array[i]);
    }

    printf("\nEnter the size of your window:");
    scanf("%d",&winsize);

    max = findmax(array,0,size);

    printf("\nThe max is:%d",max);

    return 0;
}

int findmax(int array[],int start , int end){
    int maximum,i;
    maximum = array[start];

    for(i=start;i<end;i++){
        if(maximum < array[i]){
            maximum = array[i];
        }
    }

    return maximum;
}
