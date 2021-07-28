#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int stack1[10];
    int tos;
}*STACK;

void push(STACK s,int node){
    s->stack1[++s->tos]=node;    
}

int pop(STACK s){
    int temp=s->stack1[s->tos];
    s->tos--;
    return temp;
}

typedef struct node{
    int val;
    struct node* next;
}*NODE;

typedef struct graph{
    int V;
    NODE * array;//array of addresses of type struct node
}*GRAPH;


void dfs2(GRAPH g,int i,STACK s,int* visited,int *popped){
    static int k=0;
    printf("visiting %d\n",i);
    visited[i]=1;
    push(s,i);
    NODE head=g->array[i];
    while(head){
        
        if(!visited[head->val]){
            dfs2(g,head->val,s,visited,popped);
        }
       
        head=head->next;
    }
    popped[k]=pop(s);
    printf("popped node %d\n",popped[k]);
    k++;
}

int* dfs(GRAPH g,int *visited,int *popped){    
    STACK s=(STACK)malloc(sizeof(struct stack));    
    s->tos=-1;
    popped=(int*)malloc(g->V*sizeof(int));

    //in case graph is disconnected
    for(int i=0;i<g->V;i++){
        
        if(visited[i]!=1){            
            dfs2(g,i,s,visited,popped);
        }
    }
    return popped;
}


NODE createNode(int v){
    NODE newnode=(NODE)malloc(sizeof(struct node));
    newnode->next=NULL;
    newnode->val=v;
    return newnode;
}

void addEdge(GRAPH g,int i, int v){
   NODE newnode=createNode(v);
   
   newnode->next=g->array[i];
   g->array[i]=newnode;
   
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
        while(head){
            printf("%d ->",head->val);
            head=head->next;
        }
        printf("null\n");
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
        printf("\nEnter the number of nodes directed out of vertex %d\n",i);
        scanf("%d",&n);
        printf("enter nodes end vertices from vertex %d\n",i);
        
        for(j=0;j<n;j++){
            scanf("%d",&nodeval);
            addEdge(g,i,nodeval);
        }        
    }
    //print graph
    print(g);

    int visited[v];
    for(int i=0;i<v;i++)
        visited[i]=0;
    
    int *poporder;
    poporder=dfs(g,visited,poporder);//for topological sort
    printf("One of the possible topological sort orders\n");
    for(int i=v-1;i>=0;i--){
        printf("%d\t",poporder[i]);
    }
}
