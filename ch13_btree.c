#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node * root;

void insert(struct node ** root);
void insertinpos(struct node **root, struct node *r);
void printtree(struct node *root);

int main(){
    int choice;
    root = NULL;

    while(1){
        printf("\nEnter the choice: 1.Insert 2.Delete 3.Count");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert(&root);
                break;
        }
    }


    return 0;
}


void insert(struct node ** root){
    struct node *temp,*r;
    int value;

    temp = *root;

    printf("\nEnter the value:");
    scanf("%d",&value);

    r=(struct node*)malloc(sizeof(struct node));
    r->data = value;
    r->left = NULL;
    r->right = NULL;

    insertinpos(root,r);
    printtree(*root);

}

void insertinpos(struct node **root, struct node * r){
    struct node *temp;
    temp = *root;

    if(*root == NULL){
        *root = r;
        return ;
    }
    else{
        if(temp->left == NULL){
            temp->left = r;
        }
        else if(temp->right == NULL){
            temp->right = r;
        }
        else{
            insertinpos(&(temp->left),r);
            insertinpos(&(temp->right),r);
        }
    }

}

void printtree(struct node *root){
    struct node *temp;
    temp = root;

    if(root){
        printf("NODE -> %d",root->data);
        if(root->left){
            printf("LEFT -> %d",root->left->data);
        }
        if(root->right){
            printf("RIGHT -> %d",root->right->data);
        }
        printf("\n");
        printtree(root->left);
        printtree(root->right);
    }

}
