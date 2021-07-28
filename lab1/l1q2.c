#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int val;
    struct node* next;
}*NODE;

typedef struct graph{
    int V;
    NODE * array;//array of addresses of type struct node
}*GRAPH;

NODE createNode(int v){
    NODE newnode=(NODE)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->val=v;
    return newnode;
}

void addEdge(NODE* head, int v){
   NODE newnode=createNode(v);
   newnode->next=*head;
   *head=newnode;
  
}

void initialize(GRAPH g, int vertices){
    g->V=vertices;
    g->array=(NODE*)malloc(vertices*sizeof(NODE));
    
    for(int i=0;i<vertices;i++){
        g->array[i]=NULL;
    }
}

void print(GRAPH g){
    for(int i=0;i<g->V;i++){
        printf("\n%d ->",i);
        NODE head=g->array[i];
        while(head->next){
            printf("%d ->",head->val);
            head=head->next;
        }
        printf("%d",head->val);
    }
}

int main(){
    int i,j,n,v,nodeval;
    GRAPH g=(GRAPH)malloc(sizeof(struct graph));
    printf("\nEnter number of vertices\n");
    scanf("%d",&v);
    initialize(g,v);

    //enter graph input
    for(i=0;i<v;i++){
        printf("\nEnter the number of nodes adjacent to vertex %d\n",i);
        scanf("%d",&n);
        printf("enter nodes adjacent to vertex %d\n",i);
        
        for(j=0;j<n;j++){
            scanf("%d",&nodeval);
            addEdge(&(g->array[i]),nodeval);
        }        
    }
    //print graph
        print(g);
}
