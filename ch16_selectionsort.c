
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *array,n,temp,i,j,min,swapped=1;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    array=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(i=0;i<n-1;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(array[j]< array[min]){
                min = j;
            }
            temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }

    printf("\nThe sorted array is:");

    for(i=0;i<n;i++){
        printf("\t%d",array[i]);
    }

}
