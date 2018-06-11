#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void addbegin(struct node **head);
void printlist(struct node *head);
void addend(struct node **head);
void delbeg(struct node **head);
void delend(struct node **head);
void delpos(struct node **head);
void dellist(struct node **head);

int main(){
    struct node *q;
    q = NULL;
    int choice;

    while(1){
        printf("--------------------\nEnter your operation\n--------------------\n 1.Exit\n 2.Add at beg\n 3.Add end\n 4.Delete at begin \n 5.Delete at end \n 6.Delete at position\n 7.Delete list \n");
        scanf("%d",&choice);


        switch(choice){
            case 1:
                exit(1);
            case 2:
                addbegin(&q);
                break;
            case 3:
                addend(&q);
                break;
            case 4:
                delbeg(&q);
                break;
            case 5:
                delend(&q);
                break;
            case 6:
                delpos(&q);
                break;
            case 7:
                dellist(&q);
                break;
            default:
                exit(2);
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

void delbeg(struct node **head){
    struct node *temp;
    temp = *head;

    if(*head == NULL){
        printf("The list is empty. \n");
        return;
    }

    *head = temp->next;
    free(temp);

    printlist(*head);
}

void delend(struct node **head){
    struct node *temp;
    temp = *head;

    if(*head == NULL){
        printf("The list is empty. \n");
        return;
    }

    if(temp->next == NULL){
        delbeg(head);
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next->next);
    temp->next = NULL;

    printlist(*head);
}

void delpos(struct node **head){
    struct node *temp, *temp2;
    int pos,counter=1;
    temp = *head;

    if(*head == NULL){
        printf("The list is empty. \n");
        return;
    }

    printf("\nEnter the position you want to delete:");
    scanf("%d",&pos);

    if(pos == 1){
        delbeg(head);
        return;
    }

    while(counter != pos-1){
        temp = temp->next;
        counter++;
    }
    temp2 = temp->next;
    temp->next = temp->next->next;
    free(temp2);

    printlist(*head);



}

void dellist(struct node **head){
    struct node *temp,*temp2;
    temp = *head;

    while(temp){
        temp2 = temp->next;
        free(temp);
        temp = temp2;
    }

    *head = NULL;

    printlist(*head);
}

void printlist(struct node *head){
    printf("-------------------");
    printf("\nModified List ->");
    while(head != NULL){
        printf("%d  ",head->data);
        head = head->next;
    }
    printf("\n \n");
}
