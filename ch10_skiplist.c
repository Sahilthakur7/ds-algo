#include<stdio.h>
#include<stdlib.h>

#define MAXSKIPLEVEL 5

struct node {
    int data;
    struct node *next[1];
};

struct skiplist{
    struct node *header;
    int list_level;
};

struct skiplist list;

void initList(){
    int i;
    for(i=0;i<= MAXSKIPLEVEL; i++){
        list.header->next[i] = list.header;
    }
    list.list_level = 0;
}

struct node* insertElement(int data){
    int i,newLevel;
    struct node *update[MAXSKIPLEVEL + 1];
}

int main(){
    int i,*a,maxnum = 10;
    initList();
    
    for(i=0;i<maxnum;i++){
        a[i] = rand();
        printf("Random %d items\n",maxnum);
    }

    for(i=0;i<maxnum;i++){
        insertElement(a[i]);
    }

    for(i = maxnum-1;i>=0;i--){
        findElement(a[i]);
    }

    for(i = maxnum-1;i>=0;i--){
        deleteElement(a[i]);
    }

    return 0;
}
