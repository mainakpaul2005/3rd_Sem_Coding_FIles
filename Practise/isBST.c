#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int value)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

int prev = -1000;

int isBST(struct node* root)
{
    if(root == NULL)
        return 1;

    if(!isBST(root->left))
        return 0;

    if(root->data <= prev)
        return 0;

    prev = root->data;

    return isBST(root->right);
}

int main()
{
    struct node* root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    if(isBST(root))
        printf("Tree is a BST\n");
    else
        printf("Tree is NOT a BST\n");

    return 0;
}