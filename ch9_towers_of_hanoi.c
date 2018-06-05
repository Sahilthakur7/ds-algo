#include<stdio.h>

void executeProcess(int n,char source, char dest, char aux);

int main(){
    int number=3;
    char source,destination,aux;
    source = 's';
    destination = 'd';
    aux= 'a';

    printf("Initial State: All 3 of the pegs are on source \n");
    executeProcess(number,source,destination,aux);

    return 0;
}

void executeProcess(int n,char source, char dest, char aux){
    if(n==1){
        printf("Move disk 1 from %c to %c",source,dest);
        return;
    }
    executeProcess(n-1,source,aux,dest);
    printf("\nMove disk %d from rod %c to %c\n",n,source,dest);
    executeProcess(n-1,aux,dest,source);

}
