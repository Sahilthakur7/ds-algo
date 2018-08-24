#include<stdio.h>
#include<stdlib.h>

int bin_search(int *array, int n, int k);
int binary_search(int *array, int low,int high, int k);

int main(){
    int *array,n,pass,i,swapped=1;
    int outputiterative = 0;
    int outputrecursive = 0;
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

    printf("\nEnter element to search:");
    scanf("%d",&k);


    //Iterative version

    outputiterative = bin_search(array,n,k);
    outputrecursive = binary_search(array,0,n-1,k);

    printf("\nIterative output-> %d \t Recursive output-> %d",outputiterative,outputrecursive);

}

int bin_search(int *array,int n,int k){
    int low = 0;
    int high = n-1;
    int mid;

    while(low <= high){
        mid = low + (high-low) / 2;
        if(array[mid] == k){
            return 1;
        }
        else if(array[mid] > k){
            high = mid-1;
        }
        else{
            low = mid + 1;
        }
    }

    return 2;

}

int binary_search(int *array,int low,int high , int k){
    int mid;
    mid = low + (high - low) / 2;

    if(array[mid] == k){
        return 1;
    }
    else if(array[mid] > k){
        binary_search(array,low,mid-1,k);

    }
    else
        binary_search(array,mid + 1, high, k);
}
