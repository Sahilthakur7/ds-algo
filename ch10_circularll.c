#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

void addbeg(struct node **head);
void printlist(struct node *head);

int main(){
    int choice;
    struct node *q;
    q = NULL;

    while(1){
        printf("--------------------\nEnter your operation\n--------------------\n 1.Exit\n 2.Add at beg\n 3.Add end\n 4.Delete at begin \n 5.Delete at end \n 6.Delete at position\n 7.Delete list \n");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                exit(1);
            case 2:
                addbeg(&q);
                break;
                /*     case 3: */
                /*         addend(&q); */
                /*         break; */
                /*     case 4: */
                /*         delbeg(&q); */
                /*         break; */
                /*     case 5: */
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
        *head = r;
        r->next = r;
    }
    else{
        
        while(temp->next != *head){
            printf("move");
            temp = temp->next;
        }
        r->next = *head;
        *head = r;
        temp->next = r;
    }

    printlist(*head);
}

void printlist(struct node *head){
    struct node *temp;
    temp = head;

    while(temp->next != head){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
