#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addbeg(struct node **head);
void printlist(struct node *head);
void addend(struct node **head);
void delbeg(struct node **head);

int main(){
    int choice;
    struct node *q;
    q = NULL;

    while(1){
        printf("--------------------\nEnter your operation\n--------------------\n 1.Exit\n 2.Add at beg\n 3.Add end\n 4.Delete at begin \n \n");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                exit(1);
            case 2:
                addbeg(&q);
                break;
            case 3:
                addend(&q);
                break;
            case 4:
                delbeg(&q);
                break;
                /* case 5: */
                /*         delend(&q); */
                /*         break; */
                /*     case 6: */
                /*         delpos(&q); */
                /*         break; */
                /*     case 7: */
                /*         dellist(&q); */
                /*         break; */
                /*     default: */
                /*         exit(2); */

        }
    }
    return 0;
}

void addbeg(struct node **head){
    struct node *temp,*r;
    int value;

    temp = *head;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node *)malloc(sizeof(struct node));
    r->data = value;

    if(*head == NULL){
        r->next = r;
        *head = r;
    }
    else{

        while(temp->next != *head){
            temp = temp->next;
        }
        r->next = *head;
        *head = r;
        temp->next = r;
    }

    printlist(*head);
}

void addend(struct node **head){
    struct node *temp,*r;
    int value;

    temp = *head;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node *)malloc(sizeof(struct node));
    r->data = value;

    if(*head == NULL){
        r->next = r;
        *head = r;
    }
    else{
        while(temp->next != *head){
            temp = temp->next;
        }
        temp->next = r;
        r->next = *head;
    }
    printlist(*head);
}

void delbeg(struct node **head){
    struct node *temp, *temp2;
    temp = *head;
    temp2 = *head;

    while(temp->next != *head){
        temp = temp->next;
    }

    temp->next = temp2->next;
    *head = temp->next;

    free(temp2);
    printlist(*head);

}

void printlist(struct node *head){
    struct node *temp;
    temp = head;

    if(temp->next == temp){
        printf("%d",temp->data);
        return;
    }

    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    } while(temp != head);
    printf("\n");
}
