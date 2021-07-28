#include <stdio.h>
#include <stdlib.h>

//DFS using graph representation

int graph[10][10];
int visited[10];
int V;
typedef struct stack{
    int arr[10];
    int tos;
}*STACK;

void push(STACK s, int node){
    s->arr[++(s->tos)]=node;
}

int pop(STACK s){
    int temp=s->arr[s->tos];
    (s->tos)--;
    return temp;
}

void dfs2(int node,STACK s){
    printf("Visiting node %d\n",node);
    visited[node]=1;
    printf("Pushing node %d to stack\n",node);
    push(s,node);

    for(int i=0;i<V;i++){
        if((visited[i]!=1)&&(graph[node][i]==1)&&(node!=i)){
            dfs2(i,s);
        }
    }
    printf("popping from stack: %d\n",pop(s));

}

void dfs(STACK s){
    //in case graph isnt completely connected
    for(int i=0;i<V;i++){
        if(visited[i]!=1){
            dfs2(i,s);
        }
    }
}



int main(){
    STACK s=(STACK)malloc(sizeof(struct stack));
    s->tos=-1;
   int i,j;

    printf("enter number of vertices\n");
    scanf("%d",&V);

    printf("enter graph\n");
    
    for( i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }

    dfs(s);
}
