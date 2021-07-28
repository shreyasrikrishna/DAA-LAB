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

typedef struct queue{
    int que[10];
    int front,rear;
}*Q;

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
        printf("null");
    }
}

void enqueue(Q q, int node){
    if(q->front==-1){
        q->front++;
    }
    q->que[++q->rear]=node;
}

int dequeue(Q q){
    if (q->front>q->rear)
    return -1;

    int temp=q->que[q->front++];
    return temp;
}

void deletesource(GRAPH g,int i){
    printf("%d ",i);//for order
    g->array[i]=NULL;//remove all connections of deleted
}

int indegree(GRAPH g, int node){
    int count=0;
    for(int i=0;i<g->V;i++){
        if(i==node)
        continue;
        NODE head=g->array[i];
        while(head){
            if(head->val==node)
            count++;
            head=head->next;       
           
        }
    }
    return count;
}


void topologicalSort(GRAPH g,Q q){
    int in[g->V];
    for(int i=0;i<g->V;i++){
         in[i]=indegree(g,i);
        
        if(in[i]==0){
            enqueue(q,i);
        }

    }
    printf("\nindegrees of all\n");
    for(int i=0;i<g->V;i++){
        printf("node %d indegree %d\n",i,in[i]);
    }
    printf("\nOne possible topological order is\n");
    while(q->front<=q->rear){
        int node=dequeue(q);
      
        NODE head=g->array[node];
        while(head){
            int temp=head->val;//removing connections from deleted source
            in[temp]=in[temp]-1;
            if( in[temp]==0){

                enqueue(q,temp);
            }
            head=head->next;
        }
        deletesource(g,node);
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
    Q q=(Q)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    
    topologicalSort(g,q);
}