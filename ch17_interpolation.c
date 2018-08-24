
#include<stdio.h>
#include<stdlib.h>

int intsearch(int *array,int n,int k){
    int low=0;
    int high = n-1;
    int mid;

    while(low <= high){
        mid = (low) + ((k - array[low])/(array[high]- array[low]));

        if(k == array[mid]){
            return 1;
        }
        else if(k < array[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }

    return 2;
}

int main(){
    int *array,n,pass,i,swapped=1;
    int search;
    int k;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    array=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    for(pass=n-1;pass>0 && swapped;pass--){
        swapped = 0;
        for(i=0;i<pass;i++){
            if(array[i] > array[i+1]){
                array[i+1] = array[i] + array[i+1];
                array[i] = array[i+1] - array[i];
                array[i+1] = array[i+1] - array[i];
                swapped = 1;
            }
        }
    }

    printf("\nEnter the element to be searched:");
    scanf("%d",&k);

    search = intsearch(array,n,k);

    printf("\n%d",search);

    return 0;
    
}
