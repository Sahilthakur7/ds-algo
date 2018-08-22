
#include<stdio.h>
#include<stdlib.h>

int maxfreq(int *array, int count);

int main(){
    int *array , i , j , temp , n;

    printf("Enter the number of elements:");
    scanf("%d",&n);

    array = (int *)malloc(sizeof(int)*n);

    printf("\nEnter your elements:");

    for(i=0;i<n;i++){
        scanf("%d",&array[i]);
    }

    temp = maxfreq(array,n);

    printf("\n%d has the max frequency",temp);
}

int maxfreq(int *array,int count){
    int freq,temp,i,j,winner;
    freq=0;

    for(i=0;i<count;i++){
        if(array[i] == 0){
            continue;
        }
        temp = array[i];
        array[i] = 1;
        for(j=i+1;j<count;j++){
            if(array[j] == temp){
                array[i]++; 
                array[j] = 0;
            }

        }
        if(array[i] > freq){
            freq = array[i];
            winner= temp;
        }
    }

    return winner;
}
