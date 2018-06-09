#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void addbegin(struct node **head);
void printlist(struct node *head);
void addend(struct node **head);

int main(){
    struct node *q;
    q = NULL;
    int choice;

    while(1){
        printf("Enter your operation:\n- 1.Add at begin 2.Exit 3.Add end\n");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                addbegin(&q);
                break;
            case 2:
                exit(1);
            case 3:
                addend(&q);
        }
    }
    return 0;
}

void addbegin(struct node **head){
    struct node *r;
    int value;

    printf("Enter the value:");
    scanf("%d",&value);

    r = (struct node*)malloc(sizeof(struct node));
    r->data = value;
    r->next = (*head);

    *head = r;

    printlist(*head);


}

void addend(struct node **head){
    struct node *temp,*r;
    int value;
    temp = *head;

    r=(struct node*)malloc(sizeof(struct node));
    r->next = NULL;

    printf("\nEnter the value to add at end:");
    scanf("%d",&value);
    r->data = value;

    if(*head == NULL){
        *head = r;

        printlist(*head);
        return;
    }


    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = r;

    printlist(*head);
}

void printlist(struct node *head){
    while(head != NULL){
        printf("%d  ",head->data);
        head = head->next;
    }
}
