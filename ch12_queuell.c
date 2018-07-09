#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct Queue{
    struct node *front;
    struct node *rear;
};

void enqueue(struct Queue *Q);
void printlist(struct Queue *Q);
int isEmpty(struct Queue *Q);
int dequeue(struct Queue *Q);
int QueueLength(struct Queue *Q);

int main()
{
    struct Queue *Q;
    int choice,el,size;
    Q = (struct Queue *)malloc(sizeof(struct Queue));
    Q->front = Q->rear = NULL;

    while(1){
        printf("\nEnter your choice: 1.Enqueue  2.Dequeue 3.QueuLength  5.Exit  6.QueueSize\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                enqueue(Q);
                break;
            case 2:
                if(isEmpty(Q) == 1){
                    printf("Cannot dequeue from empty\n");
                }
                else{
                    el = dequeue(Q);
                    printf("%d has been dequeued\n",el);
                }
                break;
                /* case 3: */
                /*     isFull(Q); */
                /*     break; */
                /* case 4: */
                /*     isEmpty(Q); */
                /*     break; */
                /* case 5: */
                /*     exit(1); */
                /*     break; */
                case 6:
                size = QueueLength(Q);
                printf("Size is %d",size);

        }
    }
    return 0;
}

void enqueue(struct Queue *Q){
    int value;
    struct node *r,*temp;
    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node*)malloc(sizeof(struct node));
    r->data = value;
    r->next = NULL;

    if(Q->rear == NULL){
        Q->rear = r;
        Q->front = r;
    }

    else{
        Q->rear->next = r;
        Q->rear = r;
    }

    printlist(Q);

}

void printlist(struct Queue *Q){
    struct node *temp;
    temp = Q->front;
    if(temp == Q->rear){
        printf("%d",Q->rear->data);
    }
    else{

        while(temp != Q->rear->next){
            printf("%d \t",temp->data);
            temp = temp->next;
        }

    }
}

int isEmpty(struct Queue *Q){
    if(Q->front == NULL){
        return 1;
    }
    else{
        return 2;
    }
}

int dequeue(struct Queue *Q){
    int val;
    struct node *temp;
    temp = Q->front;

    val = Q->front->data;

    Q->front = Q->front->next;

    free(temp);

    return val;
}

int QueueLength(struct Queue *Q){
    int size=0;
    struct node *temp;
    temp = Q->front;

    if(temp == NULL){
        return 0;
    }

    while(temp != Q->rear->next){
        temp = temp->next;
        size++;
    }

    return size;

}
