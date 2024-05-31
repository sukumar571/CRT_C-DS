//write a program to print binary search tree using inordertravelsal
#include<stdio.h>
#include<stdlib.h>
struct node{
    int key;
    struct node *left;
    struct node *right;
};
struct node *newnode(int item)
{
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    temp->key=item;
    temp->left=temp->right=NULL;
    return temp;
};
//function tom insert a newnode
//given key is BST
struct node * insert(struct node* node,int key)
{
    //if tree is empty means root is NULL
    if(node==NULL)
    {
        return newnode(key);
    }
    //if key is less than node traversal to left sub tree
    if(key < node->key)
    {
        node->left =insert(node->left,key);
    }
    //if key is greater than node traversal to right sub tree
    else if(key > (node->key))
    {
        node->right = insert(node->right,key);
    }
    return node;
}
//function to find the minimum element in your tree
struct node* minimumvalue(struct node* node)
{
    struct node* curr=node;
    //loop down to find theleft sub tree to find the least node of your left tree 
    while(curr && curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}
//function to find the deleted element in your list 
struct node * delete(struct node* root,int key)
{
    //base case
    if(root==NULL)
    {
        return root;
    }
    //if the key to be deleted is greater than root means check with right subtree
    if(key<root->key)
    {
        root->left=delete(root->left,key);
    }
    else if(key>root->key)
    {
        root->right=delete(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        //inorder successor
        struct node* temp=minimumvalue(root->right);
        //copy the inorder sucessor content to the root node
        root->right=delete(root->right,temp->key);
        root->key =temp->key;
    }
    return root;
}
//function to print the elements using inorder traversal

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->key);
        inorder(root->right);
    }
}
 void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->key);
    }
}
int main()
{
    struct node* root=NULL;
    root=insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);
    printf("inorder:\n");
    inorder(root);
    delete(root,50);
    printf("\nafter deleting 50 the tree is\n");
    inorder(root);
    printf("\n");
    printf("preorder:\n");
    preorder(root);
    printf("\n");
    printf("postorder:\n");
    postorder(root);
}