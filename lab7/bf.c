#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left,*right;
    int bf;
}*TREE;

int max(int a ,int b){
    return a>b ? a:b;
}

int height(TREE root){
    if (root==NULL)
    return 0;
    return 1+max(height(root->left),height(root->right));
}

void checkBf(TREE root){
    if (root==NULL)
        return;
    root->bf=height(root->left)-height(root->right);
    checkBf(root->left);
    checkBf(root->right);
}

void inorder(TREE root){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("\nnode %d and balance factor is %d",root->data,root->bf);
    inorder(root->right);

}

TREE createNode(int val){
    TREE node=(TREE)malloc(sizeof(struct tree));
    node->data=val;
    node->left=node->right=NULL;
    
    return node;
}

void insertNode(TREE root,int val){
    int i=0;
    TREE node=createNode(val);
    TREE prev=NULL;
    while(root){
        if((root->data)>val){
            prev=root;
            root=root->left;
        }
        else if(val>(root->data)){
            prev=root;
            root=root->right;
        }
    }
    
    if(val<prev->data){        
        prev->left=node;
    }
    else  prev->right=node;   
    
}

int main(){
    TREE root=(TREE)malloc(sizeof(struct tree));
    root->data=5;
    root->left=NULL;
    root->right=NULL;
    int ch,val;
    
    ch=0;
    while(ch!=3){
        printf("\nEnter your choice\n1.Insert Node 2.Print Tree 3.Exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
                printf("Enter value to be inserted\n");
                scanf("%d",&val);
                
                insertNode(root,val);
                break;
            }
            case 2:{
                checkBf(root);
                inorder(root);
                break;
            }
            case 3:{
                break;
            }
        }
    }

    
}