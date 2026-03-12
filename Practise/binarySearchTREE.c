#include<stdio.h>
#include<stdlib.h>

typedef struct binarySearchTREE{
    int data;
    struct binarySearchTREE *left;
    struct binarySearchTREE *right;
} node;

node* createNode(int val);
node* insertNode(node* root, int val);
node* findMin(node* root);
node* deleteNode(node* root, int val);
void inOrder(node* root);
void preOrder(node* root);
void postOrder(node* root);

int main(){

    int ch, val;
    node* root = NULL;

    while (1){
        printf("\nEnter your choice:\n1.Add\n2.Delete\n3.Inorder Display\n4.Pre-order Display\n5.Post-order Display\n6.Exit\n");
        scanf("%d",&ch);
        
        switch (ch){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insertNode(root, val);
                printf("Node inserted successfully!\n");
                break;
            case 2:
                if(root == NULL){
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    root = deleteNode(root, val);
                }
                break;
            case 3:
                if(root == NULL){
                    printf("Tree is empty!\n");
                } else {
                    printf("Inorder Traversal: ");
                    inOrder(root);
                    printf("\n");
                }
                break;
            case 4:
                if(root == NULL){
                    printf("Tree is empty!\n");
                } else {
                    printf("Preorder Traversal: ");
                    preOrder(root);
                    printf("\n");
                }
                break;
            case 5:
                if(root == NULL){
                    printf("Tree is empty!\n");
                } else {
                    printf("Postorder Traversal: ");
                    postOrder(root);
                    printf("\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }    

    return 0;
}

// Create a new node
node* createNode(int val){
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
node* insertNode(node* root, int val){
    if(root == NULL){
        return createNode(val);
    }
    
    if(val < root->data){
        root->left = insertNode(root->left, val);
    } else if(val > root->data){
        root->right = insertNode(root->right, val);
    }
    // If val == root->data, duplicate values are not inserted
    
    return root;
}

// Find minimum value node in a subtree
node* findMin(node* root){
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

// Delete a node from BST
node* deleteNode(node* root, int val){
    if(root == NULL){
        printf("Value not found in the tree!\n");
        return root;
    }
    
    if(val < root->data){
        root->left = deleteNode(root->left, val);
    } else if(val > root->data){
        root->right = deleteNode(root->right, val);
    } else {
        // Node found - handle 3 cases
        
        // Case 1: Leaf node (no children)
        if(root->left == NULL && root->right == NULL){
            free(root);
            printf("Node deleted successfully!\n");
            return NULL;
        }
        
        // Case 2: One child
        if(root->left == NULL){
            node* temp = root->right;
            free(root);
            printf("Node deleted successfully!\n");
            return temp;
        }
        if(root->right == NULL){
            node* temp = root->left;
            free(root);
            printf("Node deleted successfully!\n");
            return temp;
        }
        
        // Case 3: Two children
        // Find inorder successor (smallest in right subtree)
        node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    
    return root;
}

// Inorder traversal (Left, Root, Right)
void inOrder(node* root){
    if(root != NULL){
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preOrder(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postOrder(node* root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}