#include<stdio.h>
#include<stdlib.h>

int checkdup(int *array, int count);

int main(){
    int *array , i , j , temp , n;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    array = (int *)malloc(sizeof(int)*n);

    printf("\nEnter your elements:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    temp = checkdup(array,n);

    if(temp == 1){
        printf("\nYour array has duplicate elements");
    }
    else{
        printf("\nNo duplicates");
    }

    return 0;
}

int checkdup(int *array, int count){
    int temp,i,j;

    for(i=count-1 ; i >= 0 ; i--){
        for(j=0;j < i;j++){
            if(array[j]> array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }


    for(i=0;i<count;i++){
        if(array[i] == array[i+1]){
            return 1;
        }
    }

    return 0;

    /*
    for(i=0;i<count;i++){
        for(j=i+1;j<count;j++){
            if(array[i] == array[j]){
                return 1;
            }
        }
    }

    return 0;
    */
}
