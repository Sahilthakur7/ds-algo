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
int count(struct node *root);
int maximum(struct node *root);
int search(struct node *root,int element);

int main(){
    int choice,number,max,found;
    int value;
    root = NULL;

    while(1){
        printf("\nEnter the choice: 1.Insert 2.Maximum 3.Count 4.Search\n");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                insert(&root);
                break;
            case 2:
                max = maximum(root);
                printf("\nMax element is %d",max);
                break;
            case 3:
                number = count(root)  ;
                printf("\n %d ",number);
                break;
            case 4:
                printf("\nEnter the value to search:");
                scanf("%d",&value);
                found = search(root,value);
                if(found == 1){
                    printf("\nYes");
                }
                else{
                    printf("\nNO");
                }
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
            if(temp->right->left && temp->right->right){
                insertinpos(&(temp->left),r);
            }
            else if(temp->left->left && temp->left->right){
                insertinpos(&(temp->right),r);
            }
            else{
                insertinpos(&(temp->left),r);

            }}
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

int count(struct node *root){

    if(root == NULL){
        return 0;
    }
    else{
        return 1 + count(root->left) + count(root->right);
    }

}

int maximum(struct node * root){
    int max,right_max,left_max;
    max = 0;

    if(root != NULL){

        left_max = maximum(root->left);
        right_max = maximum(root->right);

        if(left_max > right_max){
            max = left_max;
        }
        else{
            max = right_max;
        }

        if(root->data > max){
            max = root->data;
        }
    }

    return max;
}

int search(struct node *root,int element){
    int found;
    int left_found,right_found;

    if(root == NULL){
        return 0;
    }

    else{
        if(root->data == element){
            return 1;
        }

        else{
            left_found = search(root->left,element);
            if(left_found == 1){
                return 1;
            }
            else{
                right_found = search(root->right,element);
                if(right_found == 1){
                    return 1;
                }
            }
        }
    }
    return 0;

}
