#include<stdlib.h>
#include<stdio.h>

struct Graph{
    int V;
    int E;
    int Adj[5][5];
};

int main(){
    struct Graph *G;
    int i,j,u,v;

    printf("Enter the value of vertices you want:");
    scanf("%d",&G->V);

    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            G->Adj[i][j] = 1;
        }
    }

    printf("\nEnter 1 for connected and 0 for not connected.");

    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            if(G->Adj[i][j] != 1 && G->Adj[j][i] != 1){
                printf("\nBetween vertex %d and vertex %d : ",i,j);
                scanf("%d",&G->Adj[i][j]);
                G->Adj[j][i] = G->Adj[i][j];
            }
        }
    }

    printf("\nRepresentation");
    for(i=0;i<G->V;i++){
        for(j=0;j<G->V;j++){
            printf("%d",G->Adj[i][j]);
        }
    }
    return 0;
}
