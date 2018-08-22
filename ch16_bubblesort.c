#include<stdio.h>
#include<stdlib.h>

int main(){
    int *array,n,pass,i,swapped=1;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    array=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(pass=n-1;pass >= 0 && swapped ; pass -- ){

        swapped = 0;

        for(i=0;i<pass ;i++){

            if(array[i] > array[i+1]){
                array[i] = array[i] + array[i+1];
                array[i+1] = array[i] - array[i+1];
                array[i] = array[i] - array[i+1];

                swapped = 1;
            }
        }
    }

    printf("\nSorted array:");

    for(i=0;i<n;i++){
        printf("\t%d",array[i]);
    }

    return 0;
}
