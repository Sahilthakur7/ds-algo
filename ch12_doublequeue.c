#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct queue {
    struct node* front;
    struct node* rear;
};

void insertfront(struct queue** Q);
void insertrear(struct queue** Q);
void print(struct queue* Q);
void removefront(struct queue** Q);
void removerear(struct queue** Q);

int main(){
    int choice;
    struct queue *Q;
    Q->front = NULL;
    Q->rear = NULL;

    while(1){
        printf("\nEnter the operation you want to perform: 1.InsertFront 2.InsertRear 3.RemoveFront 4.RemoveRear ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insertfront(&Q);
                break;
            case 2:
                insertrear(&Q);
                break;
            case 3:
                removefront(&Q);
                break;
            case 4:
                removerear(&Q);
                break;
        }
    }
    return 0;
}


void insertfront(struct queue** Q){
    struct node *temp,*r;
    int value;
    temp = (*Q)->front;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node *)malloc(sizeof(struct node));
    r->data = value;
    
    if(temp == NULL){
        (*Q)->front = r;
        (*Q)->rear = r;
        r->next = NULL;
    }
    else{
        r->next = temp;
        (*Q)->front = r;
    }

    print(*Q);
}

void insertrear(struct queue** Q){
    struct node *temp,*r;
    int value;
    temp = (*Q)->front;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node *)malloc(sizeof(struct node));
    r->data = value;

    if(temp == NULL){
        (*Q)->front = r;
        (*Q)->rear = r;
        r->next = NULL;
    }
    else{
        r->next = NULL;
        (*Q)->rear->next = r;
        (*Q)->rear = r;
    }

    print(*Q);

}

void removefront(struct queue** Q){
    int value;
    struct node *temp;
    temp = (*Q)->front;
    if(temp == NULL){
        printf("Empty");
        return;
    }

    value = temp->data;

    if(temp->next == NULL){
        (*Q)->front = NULL;
        free(temp);
    }
    else{
        (*Q)->front = (*Q)->front->next;
        free(temp);
    }

    print(*Q);

}

void removerear(struct queue** Q){
    int value;
    struct node *temp,*temp2;
    temp2=(*Q)->front;
    temp = (*Q)->rear;

    if(temp == NULL){
        printf("EMpty");
        return;
    }

    if(temp2 ->next == NULL){
        (*Q)->front = NULL;
        free(temp);
    }
    else{
        while(temp2->next->next != NULL){
            temp2 = temp2->next;
        }
        free(temp2->next);
        temp2->next = NULL;
        (*Q)->rear = temp2;
    }

    print(*Q);

}

void print(struct queue* Q){
    struct node *temp;
    temp = Q->front;

    while(temp != NULL){
        printf("\t%d",temp->data);
        temp = temp->next;
    }
}
