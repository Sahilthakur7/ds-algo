#include<stdio.h>

#define MAX_LIMIT 10
char string[10];
char array[10];

void binary(int number);

int main(){
    int count=0;

    printf("Enter your strings using ? as wildcard\n");
    
    fgets(string,MAX_LIMIT,stdin);
    
    while(string[count] != '\0'){
        count++;
    }

    binary(count-1);

    return 0;
}

void binary(int number){
    if(number<1){
        printf("%s\n",array);
    }
    else{
        array[number-1] = '0';
        binary(number -1 );
        array[number-1] = '1';
        binary(number - 1);
    }
}
