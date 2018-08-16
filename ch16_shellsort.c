
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *a,n,loc,i,j,temp,gap;

    printf("Enter the number of elements in the array:");
    scanf("%d",&n);

    a=(int *)malloc(sizeof(int)* n);

    printf("\nEnter the elements of your array:");

    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }


    for(gap=n/2;gap>0;gap/=2)
    {
        for(i=gap;i<n;i+=1)
        {
            temp=a[i];

            for(j=i;j>=gap&&a[j-gap]>temp;j-=gap)
                a[j]=a[j-gap];

            a[j]=temp;

        }

    }

    printf("\nThe sorted array is:");

    for(i=0;i<n;i++){
        printf("\t%d",a[i]);
    }


}
