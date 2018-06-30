#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **S);
void printstack(struct node *S);
int pop(struct node **S);

int main(){
    int choice;
    struct node *S;
    int popped;
    S = NULL;
    while(1){
        printf("\nEnter the operation you want to perform\n1.Push  2.Pop ");
        scanf("%d",&choice);
        switch(choice){
            case 1:

                push(&S);
                break;
            case 2:
                popped = pop(&S);
                printf("%d has been popped\n",popped);
                printstack(S);
                break;
                /*     case 3: */
                /*         is_empty = isEmpty(S); */
                /*         if(is_empty == 1){ */
                /*             printf("Yes it is empty\n"); */
                /*         } */
                /*         else{ */
                /*             printf("Not empty\n"); */
                /*         } */
                /*         break; */
                /*     case 4: */
                /*         is_full = isFull(S); */
                /* if(is_full == 1){ */
                /*     printf("Yes it is full\n"); */
                /* } */
                /* else{ */
                /*     printf("Not full\n"); */
                /* } */
                /* break; */
                /* case 5: */
                /* exit(1); */
                /* break; */
                /* default: */
                /* exit(1); */

        }
    }

    return 0;
}


void push(struct node **S){
    struct node *temp,*r;
    int value;
    temp = *S;
    printf("\nEnter the value:");
    scanf("%d",&value);

    r=(struct node *)malloc(sizeof(struct node));
    r->data = value;

    if(temp == NULL){
        r->next = NULL;
        *S = r;
    }
    else{
        r->next = temp;
        *S = r;
    }

    printstack(*S);
}

void printstack(struct node *S){
    while(S != NULL){
        printf("%d\t",S->data);
        S = S->next;
    }

}

int pop(struct node **S){
    struct node *temp;
    int holder;
    temp = *S;

    holder = temp->data;

    *S = temp->next;
    free(temp);

    return holder;
}
