
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *array,n,loc,i,j,temp,h;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    array=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }


    for(h=n/2;h>0;h = h/3){
        for(i=1;i<n-1;i++){
            {
                if(array[i] > array[i+1]){
                    loc = i + 1;
                    temp = array[i + 1];
                }

                while(loc > 0 && array[loc-1] > temp){
                    array[loc] = array[loc -1];
                    loc --;
                }
                array[loc] = temp;
            }
        }
    }

    printf("\nThe sorted array is:");

    for(i=0;i<n;i++){
        printf("\t%d",array[i]);
    }


}
