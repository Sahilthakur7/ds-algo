#include<stdio.h>

int checksort(int array[],int size);

int main(){
    int array[5];
    int res=0;
    int i;

    printf("Enter your array of 5 numbers\n");
    for(i=0;i<5;i++){
        scanf("%d",&array[i]);
    }

    res = checksort(array,5);

    if(res ==0){
        printf("Your array is not sorted\n");
    }
    else{

        printf("Your array is sorted\n");
    }
    return 0;
}

int checksort(int array[],int size){
    int index = size -1;
    if(index==0){
        return 1;
    }
    else if(array[index] >= array[index-1]){
        return checksort(array,size-1);
    }
    else
        return 0;
}


