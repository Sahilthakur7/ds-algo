#include<stdio.h>
#include<stdlib.h>

void quicksort(int *array,int low, int high);
int partition(int *array,int low,int high);
void swap(int *x,int *y);

int main(){
    int *array,n,pass,i,swapped=1;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    array=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    quicksort(array,0,n-1);

    printf("\nYour sorted array is:");

    for(i=0;i<n;i++){
        printf("\t%d",array[i]);
    }


}

void quicksort(int *array,int low, int high){
    int pivot;

    if(low < high){
        pivot = partition(array,low,high);
        quicksort(array,low,pivot -1);
        quicksort(array, pivot + 1, high);
    }
}

int partition(int *array, int low, int high){
    int i,j,pivot;
    pivot = array[high];
    i = low - 1;

    for(j=low; j<= high -1; j++){
        if(array[j] <= pivot){
            i++;
            swap(&array[i],&array[j]);
        }
    }
    swap(&array[i+1],&array[high]);
    return (i+1);
}

void swap(int *x , int *y){
    int temp; 

    temp = *x;
    *x = *y;
    *y = temp;
}
