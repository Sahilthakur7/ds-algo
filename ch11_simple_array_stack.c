#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

struct ArrayStack{
    int top;
    int capacity;
    int *array;
};

void push(struct ArrayStack *S);
void printstack(struct ArrayStack *S);
int pop(struct ArrayStack *S);
int isEmpty(struct ArrayStack *S);
int isFull(struct ArrayStack *S);

int main(){
    int choice,popped,is_empty;
    int is_full;
    struct ArrayStack *S = malloc(sizeof(struct ArrayStack));
    S->capacity = MAXSIZE; 
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    while(1){
        printf("\nEnter the operation you want to perform\n1.Push  2.Pop  3.IsEmpty?  4.IsFull?  5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                if(isFull(S) == 1){
                    printf("The stack is full");

                }
                else{
                    push(S);
                }
                break;
            case 2:
                if(isEmpty(S) == 1){
                    printf("Can't pop off empty stack");
                }
                else{
                    popped = pop(S);
                    printf("%d has been popped\n",popped);
                    printstack(S);
                }
                break;
            case 3:
                is_empty = isEmpty(S);
                if(is_empty == 1){
                    printf("Yes it is empty\n");
                }
                else{
                    printf("Not empty\n");
                }
                break;
            case 4:
                is_full = isFull(S);
                if(is_full == 1){
                    printf("Yes it is full\n");
                }
                else{
                    printf("Not full\n");
                }
                break;
            case 5:
                exit(1);
                break;
            default:
                exit(1);

        }
    }
    return 0;
}

void push(struct ArrayStack *S){
    int value;
    printf("Enter the value to be pushed:");
    scanf("%d",&value);
    S->top++;
    S->array[S->top] = value;
    printstack(S);
}


int pop(struct ArrayStack *S){

    int popped = S->array[S->top];
    S->top --;
    return popped;

}

int isEmpty(struct ArrayStack *S){
    if (S->top == -1){
        return 1;
    }
    else {
        return 2;
    }
}

int isFull(struct ArrayStack *S){
    if (S->top == S->capacity -1){
        return 1;
    }
    else {
        return 2;
    }
}

void printstack(struct ArrayStack *S){
    int i=-1;
    while(i != S->top){
        printf("%d\t",S->array[i+1]);
        i++;
    }
}
