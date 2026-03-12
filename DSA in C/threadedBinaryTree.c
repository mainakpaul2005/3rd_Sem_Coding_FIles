#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    int lthread;
    int rthread;
};

struct Node* create(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    temp->lthread = temp->rthread = 1;
    return temp;
}

struct Node* insert(struct Node* root, int key) {
    struct Node *ptr = root, *parent = NULL;

    while (ptr != NULL) {
        if (key == ptr->data) {
            printf("Duplicate key\n");
            return root;
        }

        parent = ptr;

        if (key < ptr->data) {
            if (ptr->lthread == 0)
                ptr = ptr->left;
            else
                break;
        }
        else {
            if (ptr->rthread == 0)
                ptr = ptr->right;
            else
                break;
        }
    }

    struct Node* temp = create(key);

    if (parent == NULL) {
        root = temp;
    }
    else if (key < parent->data) {
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = 0;
        parent->left = temp;
    }
    else {
        temp->left = parent;
        temp->right = parent->right;
        parent->rthread = 0;
        parent->right = temp;
    }

    return root;
}

struct Node* inorderSuccessor(struct Node* ptr) {
    if (ptr->rthread == 1)
        return ptr->right;

    ptr = ptr->right;
    while (ptr->lthread == 0)
        ptr = ptr->left;

    return ptr;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;

    struct Node* ptr = root;

    while (ptr->lthread == 0)
        ptr = ptr->left;

    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = inorderSuccessor(ptr);
    }
}

int main() {
    struct Node* root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Inorder Traversal (Without Recursion):\n");
    inorder(root);

    return 0;
}