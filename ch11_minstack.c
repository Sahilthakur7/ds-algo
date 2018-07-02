
#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node *next;
};


void push(struct node **S , struct node **S2);
void push_aux(struct node **S,int data);
int pop(struct node **S);
int pop_aux(struct node **S);
int top_aux(struct node **S);
void printstack(struct node *S);

int main(){
    int choice;
    struct node *S;
    struct node *S2;
    int popped,popped2;
    int min;
    S = NULL;
    while(1){
        printf("\nEnter the operation you want to perform\n1.Push  2.Pop  3.Find minimum");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                push(&S,&S2);
                break;
            case 2:
                popped = pop(&S);
                popped2 = pop(&S2);
                printf("%d has been popped\n",popped);
                printstack(S);
                break;
            case 3:
                min = top_aux(&S2);
                printf("The minimum element is %d",min);
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


void push(struct node **S,struct node **S2){
    struct node *temp,*r,*r2,*temp2;
    int value;
    temp = *S;
    temp2 = *S2;
    printf("\nEnter the value:");
    scanf("%d",&value);

    r=(struct node *)malloc(sizeof(struct node));
    r2=(struct node *)malloc(sizeof(struct node));

    if(temp == NULL){
        r->data = value;
        r->next = NULL;
        *S = r;
        *S2 = r;
    }
    else{
        if(value > (*S2)->data){
            push_aux(S2,((*S2)->data));
        }
        else{
            r2->data = value;
            r2->next = temp2;
            *S2 = r2;
        }
        r->next = temp;
        *S = r;
        r->data = value;
    }


    printstack(*S);
}

void push_aux(struct node **S, int value){
    struct node *r;
    r = (struct node *)malloc(sizeof(struct node));
    r->data = value;
    r->next = *S;
    *S = r;
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

int top_aux(struct node **S){
    struct node *temp;
    int top;
    temp = *S;

    top = temp->data;

    return top;
}
