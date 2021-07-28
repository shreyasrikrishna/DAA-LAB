#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
    int data;
    struct tree *left,*right;
    int bf;
}*TREE;

typedef struct store{
    TREE badbf;
    TREE par;
    
}*STORE;

int max(int a ,int b){
    return a>b ? a:b;
}

int height(TREE root){
    if (root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

void inorder(TREE root){
    if(root==NULL)
    return;
    inorder(root->left);
    printf("\nnode %d and balance factor is %d\n",root->data,root->bf);
    inorder(root->right);

}

TREE createNode(int val){
    TREE node=(TREE)malloc(sizeof(struct tree));
    node->data=val;
    node->left=node->right=NULL;
    
    return node;
}

void finalBf(TREE root){
    if (root==NULL)
        return;
    root->bf=height(root->left)-height(root->right);
    finalBf(root->left);
    finalBf(root->right);
}

void checkBf(TREE root,STORE s,int* flag,TREE parent){
    
    if (root==NULL)
        return;
    
    root->bf=height(root->left)-height(root->right);
   
   
    if(root->bf > 1 || root->bf <-1){
        *flag=1;
        s->badbf=root;
        s->par=parent;                 
    }

    if(root->left)
        checkBf(root->left,s,flag,root);
    if(root->right)
        checkBf(root->right,s,flag,root);
    
}


TREE rshift(TREE parent,TREE badbf,TREE root){//returns root in case root is the one being changed
    //changes links
     printf("\nDoing right shift\n");
    if(parent==NULL){//ie badbf is root
        TREE r2=badbf->left;
        badbf->left=r2->right;
        r2->right=badbf;

        return r2;//new root
    }

    TREE temp=badbf->left;

     //check if badbf on right or left of parent
    if(badbf->data<parent->data){
        //on left        
        parent->left=temp;        
    }

    else{
        //on right        
        parent->right=temp;             
    }

    badbf->left=temp->right;
    temp->right=badbf; 
    
    return root;

}

TREE lshift(TREE parent,TREE badbf,TREE root){ //returns root in case root is the one being changed
    //changes links
    printf("\nDoing left shift\n");
    if(parent==NULL){//ie badbf is root
        TREE r2=badbf->right;
        badbf->right=r2->left;
        r2->left=badbf;

        return r2;//new root
    }
    TREE temp=badbf->right;
    //check if badbf on right or left of parent
    if(badbf->data<parent->data){
        //on left        
        parent->left=temp;        
    }
    else{
        //on right        
        parent->right=temp;       
    }

    badbf->right=temp->left;
    temp->left=badbf;
    return root;

}

TREE lrshift(TREE parent,TREE badbf,TREE root){
     printf("\nDoing left right shift\n");
    if(parent==NULL){//badbf is root
        TREE temp=badbf->left->right;
        if(temp->left){
            badbf->left->right=temp->left;
        }
        temp->left=badbf->left;

        if(temp->right){
            badbf->left=temp->right;
        }
        temp->right=badbf;
        return temp;

    }
    
    TREE temp=badbf->left->right;
    if(badbf->data<parent->data){        
        parent->left=temp;        
    }
    else{
        parent->right=temp;
    }
    
    badbf->left->right=temp->left;
    
    temp->left=badbf->left;

    
    badbf->left=temp->right;
    
    temp->right=badbf;

    return root;
}

TREE rlshift(TREE parent,TREE badbf,TREE root){
    printf("\nDoing right left shift\n");
     
    if(parent==NULL){
        TREE temp=badbf->right->left;
        if(temp->left){
            badbf->right=temp->left;
        }
        temp->left=badbf;

        if(temp->right){
            badbf->right->left=temp->right;
        }
        temp->right=badbf->right;
        return temp;
    }

    TREE temp=badbf->right->left;
    if(badbf->data<parent->data){
        parent->left=temp;
    }
    else{
        parent->right=temp;
    }
    if(temp->left){
        
        badbf->right=temp->left;
    }
    
    temp->left=badbf;
    

    if(temp->right){
        badbf->right->left=temp->right;
    }
    else badbf->right->left=NULL;
        temp->right=badbf->right;
    
    if(!temp->left)
        badbf->right=NULL;
    badbf->right=NULL;
    return root;

}

TREE insertNode(TREE root,int val){
    int i=0;
    TREE node=createNode(val);
    TREE prev=NULL;
    TREE r1=root;
    while(r1){
        if((r1->data)>val){
            prev=r1;
            r1=r1->left;
        }
        else if(val>(r1->data)){
            prev=r1;
            r1=r1->right;
        }
    }
    
    if(val<prev->data){        
        prev->left=node;
    }
    else  prev->right=node;
    
    int flag=0; 
    STORE s=(STORE)malloc(sizeof(struct store));
    s->badbf=NULL;
    s->par=NULL;

    checkBf(root,s,&flag,NULL);  

    if(flag==0){
        printf("\nValid insertion\n");
    }
    else{
        printf("\nmaking chnages");
        printf("\nheight before modification is %d\n",height(root));
        //find whether right insertion or left caused bad bf
        if(val>(s->badbf->data)){
            //right heavy
            //find whether L shift needed or RL shift
            if(val<s->badbf->right->data){
                //RL shift needed
                root=rlshift(s->par,s->badbf,root);                
            }
            else{
                //L shift needed
               root= lshift(s->par,s->badbf,root);
            }
        }
        else if(val<(s->badbf->data)){
            //left heavy
            if(val<s->badbf->left->data){
                //R shift needed
                root=rshift(s->par,s->badbf,root);
            }
            else{
                //lr shift needed
                root=lrshift(s->par,s->badbf,root);
            }
        }
        printf("\nheight after modification is %d\n",height(root));
    }
   
    return root;
    
}

int main(){
    TREE root=(TREE)malloc(sizeof(struct tree));
    root->data=10;
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
                
                root=insertNode(root,val);
                break;
            }
            case 2:{
                finalBf(root);
                inorder(root);
                break;
            }
            case 3:{
                break;
            }
        }
    }

}