#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};


void insert(struct node **root,int value);
void printtree(struct node *root);
int max(struct node *root);
int search(struct node *root, int value);
void delete(struct node **root,int value);

int main(){
    struct node *root;
    root = NULL;
    int choice,value,largest;

    while(1){
        printf("\nEnter the operation you want to execute: 1.Insert 2.Delete 3.Maximum 4.Search 5.Print\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("\nEnter the value:");
                scanf("%d",&value);
                insert(&root,value);
                break;
            case 2:
                printf("\nEnter the value:");
                scanf("%d",&value);
                delete(&root,value);
                break;
            case 3:
                largest = max(root);
                printf("%d is the largest element",largest);
                break;
            case 4:
                printf("\nEnter the value:");
                scanf("%d",&value);
                if(search(root,value) == 1){
                    printf("\nYes,found");
                }
                else{
                    printf("\nNo,Not found");
                }
                break;
            case 5:
                printtree(root);
                break;
        }
    }
    return 0;
}

void insert(struct node **root,int value){
    struct node *temp,*store;
    store = *root;

    temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;

    if(*root == NULL){
        *root = temp;
    }
    else{
        if((store)->data > value){
            insert(&(store)->left,value);
        }
        else{
            insert(&(store)->right,value);
        }
    }

}

void printtree(struct node *root){
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

int max(struct node *root){
    int largest;

    if(root->right){
        while(root->right){
            root = root->right;
        }
    }
    else{
        return root->data;
    }

    largest = root->data;
    return largest;
}

int search(struct node *root, int value){
    int found;
    if(root->data == value){
        found = 1;
        return found;
    }
    else{
        if(root->data > value){
            if(root->left){
                search(root->left,value);
            }
            else return 0;
        }
        else{
            if(root->right){
                search(root->right,value);
            }
            else return 0;
        }
    }
}

