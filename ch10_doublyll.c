#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void addbeg(struct node **head);
void printlist(struct node *head);
void addend(struct node **head);
void delbeg(struct node **head);
void delend(struct node **head);
void delpos(struct node **head);
void dellist(struct node **head);

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

void addbeg(struct node **head){
    struct node *temp,*r;
    int value;
    temp = *head;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node*)malloc(sizeof(struct node));
    r->data = value;


    r->prev = NULL;

    r->next = *head;
    if(temp){
        temp->prev = r;
    }
    *head = r;

    printlist(*head);
}

void addend(struct node **head){
    struct node *temp,*r;    
    int value;
    temp = *head;


    if(temp == NULL){
        addbeg(head);
        return;
    }

    printf("\nEnter the value:");
    scanf("%d",&value);

    r = (struct node*)malloc(sizeof(struct node));
    r->data = value;

    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = r;
    r->prev = temp;
    r->next = NULL;
    printlist(*head);
}

void delbeg(struct node **head){
    struct node *temp;
    temp = *head;

    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }

    *head = temp->next;
    (*head)->prev = NULL;
    free(temp);

    printlist(*head);

}

void delend(struct node **head){
    struct node *temp;
    temp = *head;

    if(temp->next == NULL){
        *head = NULL;
        free(temp);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }

    (temp->prev)->next = NULL;
    free(temp);

    printlist(*head);
}

void delpos(struct node **head){
    struct node *temp;
    int pos,counter = 0;

    temp = *head;

    printf("\nEnter the pos to be deleted:");
    scanf("%d",&pos);

    if(pos == 1){
        delbeg(head);
        return;
    }

    while(counter+1 != pos){
        counter++;
        temp = temp->next;
    }

    if(temp->next == NULL){
        delend(head);
        return;
    }

    (temp->prev)->next = temp->next;
    (temp->next)->prev = temp->prev;
    free(temp);

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
