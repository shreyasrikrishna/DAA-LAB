#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left, *right;
}*TREE;

TREE createNode(int val){
    TREE node=(TREE)malloc(sizeof(struct tree));
    node->data=val;
    node->left=node->right=NULL;
    printf("node created\n");
    return node;
}

void insertNode(TREE root, char* path,int val){
    int i=0;
    TREE node=createNode(val);
    TREE prev=NULL;
    char temp;
    while(path[i]!='\0'&&root){
        if(path[i]=='l'){
           // printf("char scanned is l\n");
            prev=root;
            temp=path[i];
            root=root->left;
            i++;
        }
        else{
            //printf("char scanned is r\n");
            prev=root;
            temp=path[i];
            root=root->right;
            i++;
        }
    }
    if(!root&&path[i]=='\0'){
        if(temp=='l'){
            prev->left=node;
        }
        else{
            prev->right=node;
        }
    }
    else printf("wrong path\n");
}

int countNodes(TREE root,int *op){
    (*op)++;
    if(root==NULL)
    return 0;
    else return (1 + countNodes(root->left,op)+countNodes(root->right,op));
}

int main(){
    int val,i,j;
    TREE root=(TREE)malloc(sizeof(struct tree));
    printf("enter value for root node");
    scanf("%d",&val);
    root->data=val;
    root->left=root->right=NULL;

    int ch;
    char path[10];
    do{
        printf("enter your choice\n\n 1.insert new node 2. exit ");
        scanf("%d",&ch);
        if(ch==2)
        break;
        printf("enter valid path for node insertion\n");
        scanf("%s",path);
        printf("insert valid value for node\n");
        scanf("%d",&val);
        insertNode(root,path,val);

    }while(ch!=2);
    int opc=0;

    int res=countNodes(root,&opc);
    printf("\nnumber of nodes are %d\n",res);
    printf("\nopcount is%d\n",opc);

}