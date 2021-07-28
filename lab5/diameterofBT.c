#include<stdio.h>
#include<stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
}*NODE;
 

NODE newNode(int data)
{
    NODE node= (NODE)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return (node);
}
 

int max(int a, int b) {
    return (a > b) ? a : b; 
}
 

int height(NODE node)
{
    // base case tree is empty
    if (node == NULL)
        return 0;
 
   
    return( 1 + max(height(node->left), height(node->right)));
}

int diameter(struct node* tree)
{
    // base case where tree is empty
    if (tree==NULL)
        return 0;
 
    
    int lheight = height(tree->left);
    int rheight = height(tree->right);
 
    // get the diameter of left and right sub-trees
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
 
    return max(lheight + rheight + 1,max(ldiameter, rdiameter));
}

int main()
{    
    NODE root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
 
    
    printf("Diameter of the given binary tree is %d\n",diameter(root));
 
    return 0;
}