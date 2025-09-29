// Implementation of Singly Linked List
#include <stdio.h>
#include <stdlib.h>

// Structure Definition
typedef struct Node {
    int data;
    struct Node* next;
} node;

// Insert newnode at end 
void insert_newnode_end(node** head, int n);
// Display the linked list from the start
void display(node* head);

int main()
{
    int ch, n;
    node* head = NULL;
    
    while (1)
    {
        printf("\nEnter:\n 1: Insert NewNode at End:\n 2: Display:\n 3: Exit:\n");
        printf("Choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &n);
                insert_newnode_end(&head, n);
                break;

            case 2:
                display(head);
                break;
            
            case 3:
                printf("Thank You..\n");
                exit(0);

            default:
                printf("Invalid Choice! Enter correctly\n");
        }
    }

    return 0;
}

// Insert newnode at end 
void insert_newnode_end(node** head, int n)
{
    node* newnode = (node*) malloc(sizeof(node));
    newnode->data = n;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
}

// Display the linked list from the start
void display(node* head)
{
    if (head == NULL)
    {
        printf("List is Empty.\n");
        return;
    }
    node* temp = head;
    printf("The Singly Linked List: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
