#include<stdio.h>

#define MAX_LIMIT 10

struct ArrayWrapper{
    char array[10];
};


void generate(struct ArrayWrapper obj,int number , int count);

int main(){
    struct ArrayWrapper obj;
    char string[10];
    int count=0;
    int i,j=0;

    printf("Enter your strings using ? as wildcard\n");
    
    fgets(string,MAX_LIMIT,stdin);
    
    while(string[count] != '\0'){
        count++;
    }

    for(i=0;i<count;i++){
        obj.array[i] = string[i];
    }


    count = count -1 ;

    generate(obj,0,count);

    return 0;
}

void generate(struct ArrayWrapper obj,int i,int count){
    printf("%d\n",i);

    if(i == count){
        printf("%s",obj.array);
        return;
    }

    if(obj.array[i] == '?'){
        obj.array[i] = '0';
        generate(obj, i+1 , count);
        obj.array[i] = '1';
        generate(obj,i+1, count);
    }
    else
        generate(obj,i+1,count);
    

}


//Lesson: arrays are always passed by reference in C. To pass them by value(so that there values does not change) use struc ArrayWrapper.
