#include <stdio.h>
#include <stdlib.h>
typedef struct treeptr{
    int data;
    struct treeptr* left;
    struct treeptr* right;

}*TREE;

TREE makeNode(int val){
    TREE temp=(TREE)malloc(sizeof(struct treeptr));
    temp->data=val;
    temp->right=temp->left=NULL;
}

void insert(TREE root,int val){
    if(root==NULL){
        
        root=makeNode(val);
        return;
    }
    else {
        if((root->data)>val){
            if(root->left==NULL){
                root->left=makeNode(val);
                return;
            }
            else
                insert(root->left,val);
        }
        else{
            if((root->data)<val){
                 if(root->right==NULL){
                     root->right=makeNode(val);
                    return;
            }
            else
                insert(root->right,val);

            }
        }
    }
    
     
}

int search(TREE root,int key){
    if(root==NULL){
        printf("key not found\ninserting now\n");
        return 0;
    }
    if(key==root->data){
        printf("key found!");
        return 1;
    }
    else{
        if(key<root->data){
           return search(root->left,key);
        }
        if(key>root->data)
          return  search(root->right,key);
    }
}

void in(TREE root){
    if(root==NULL)
        return;
    in(root->left);
    printf("%d ",root->data);
    in(root->right);
}

void pre(TREE root){
    if(root==NULL)
        return;

    printf("%d ",root->data);
    pre(root->left);
    pre(root->right);
}

void post(TREE root){
    if(root==NULL)
        return;

    post(root->left);
    post(root->right);
    printf("%d ",root->data);
}

int main(){
    //create a binary tree
    TREE root=(TREE)malloc(sizeof(struct treeptr));
    //root=NULL;
    int rval,ch,key,val,o;
    printf("enter value for root of tree");
    scanf("%d",&rval);
    root->data=rval;
    root->left=root->right=NULL;

  do {printf("enter your choice\n");
    printf("1.Insert to tree 2.Search for key 3.Display 4.exit\n");
    scanf("%d",&ch);

    switch(ch){
        case 1:{
            printf("ente value to be inserted\n");
            scanf("%d",&val);
            insert(root,val);
            break;
        }
        case 2:{
            printf("enter key to be searched\n");
            scanf("%d",&key);
            int flag=search(root,key);
            if(flag==0)
                insert(root,key);
            break;
        }

        case 3:{
            printf("enter which order\n1.inorder 2.preorder 3.postorder\n");
            scanf("%d",&o);
            switch(o){
                case 1:
                 in(root);
                 break;
                case 2:
                    pre(root);
                    break;
                case 3:
                    post(root);
                    break;
           }
           break;
        }
    }}while(ch!=4);

}