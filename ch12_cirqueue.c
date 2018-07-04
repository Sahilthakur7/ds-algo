#include<stdio.h>
#include<stdlib.h>

#define SIZE 10

struct ArrayQueue{
    int front,rear;
    int capacity;
    int *array;
};

void enqueue(struct ArrayQueue *Q);
void printqueue(struct ArrayQueue *Q);
int dequeue(struct ArrayQueue *Q);
void isFull(struct ArrayQueue *Q);
void isEmpty(struct ArrayQueue *Q);

int main(){
    int choice;
    int el;
    struct ArrayQueue *Q = (struct ArrayQueue *)malloc(sizeof(struct ArrayQueue));

    Q->capacity = SIZE;
    Q->array = malloc(Q->capacity * sizeof(int));
    Q->front = -1;
    Q->rear = -1;

    while(1){
        printf("\nEnter your choice: 1.Enqueue  2.Dequeue  3.IsFull  4.IsEmpty  5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(Q);
                break;
            case 2:
                el = dequeue(Q);
                printf("%d has been dequeued\n",el);
                break;
            case 3:
                isFull(Q);
                break;
            case 4:
                isEmpty(Q);
                break;
            case 5:
                exit(1);
        }
    }
    return 0;
}

void enqueue(struct ArrayQueue *Q){
    int value;

    printf("Enter the value to add:");
    scanf("%d",&value);

    if(Q->front == -1){
        Q->front = Q->front + 1;
        Q->array[Q->front] = value;
        Q->rear = Q->rear + 1;
        Q->array[Q->rear] = value;
    }
    else{
        Q->rear = Q->rear + 1;
        Q->array[Q->rear] = value;
    }

    printqueue(Q);
}

int dequeue(struct ArrayQueue *Q){
    int value;

    value = Q->array[Q->front];
    Q->front = Q->front + 1;

    return value;

}

void isFull(struct ArrayQueue *Q){
    if(Q->front == Q->rear + 1){
        printf("Yes it is full\n");
    }
    else{
        printf("no, it is not full\n");
    }
}

void isEmpty(struct ArrayQueue *Q){
    if(Q->front = -1){
        printf("Yes it is empty");
    }
    else{
        printf("no, it is not empty\n");
    }
}

void printqueue(struct ArrayQueue *Q){
    int i= Q->front;

    if(Q->rear == 0){
        printf("%d",Q->array[Q->rear]);
        return ;
    }

    while(i != Q->rear + 1 ){
        printf("%d\t",Q->array[i]);
        i++;
    }
}


