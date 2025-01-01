#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void graphgeneration(int n,int **graph){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            graph[i][j]=rand()%2;
        }
    }
}
void degreecalculation(int n,int **graph,int *totalIn,int *totalOut){
    int i,j;
    for(i=0;i<n;i++){
        int In=0,Out=0;
        for(j=0;j<n;j++){
            if(graph[i][j]==1){
                Out++;
            }
            if(graph[j][i]==1){
                In++;
            }
        }
        *totalIn+=In;
        *totalOut+=Out;
    }
}
int main() {
    int n;
    int **graph;
    int totalIn=0,totalOut=0;
    printf("Enter the number of vertices: ");
    scanf("%d",&n);
    graph=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++){
        graph[i]=(int *)malloc(n*sizeof(int));
    }
    srand(time(0));

    clock_t start=clock();

    graphgeneration(n,graph);
    degreecalculation(n,graph,&totalIn,&totalOut);
    
    clock_t end=clock();

    double c_time=(double)(end-start)/CLOCKS_PER_SEC*1000;

    printf("Computational time: %.2f ms\n", c_time);
    printf("Total In-Degree: %d\n", totalIn);
    printf("Total Out-Degree: %d\n", totalOut);
    printf("Sum of In-Degrees == Sum of Out-Degrees: %s\n", (totalIn == totalOut) ? "True" : "False");

    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);
    return 0;
}