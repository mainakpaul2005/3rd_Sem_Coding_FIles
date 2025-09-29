#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void enqueue(struct Node** front, struct Node** rear, int value);
int dequeue(struct Node** front, struct Node** rear);
void display(struct Node* front);

int main() 
{
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice = 0, value;
    
    while (choice != 4) 
    {
    	printf("Queue Using Linked-List: \n");
    	printf("------------------------");
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            printf("Enter value: ");
            scanf("%d", &value);
            enqueue(&front, &rear, value);
            printf("The enqueued element is: %d\n",value);
        } 
        else if (choice == 2) 
        {
            if (front == NULL)
                printf("Queue Underflow\n");
            else
                printf("Dequeued: %d\n", dequeue(&front, &rear));
        } 
        else if (choice == 3) 
        {
            if (front == NULL)
                printf("Queue is empty\n");
            else
                display(front);
        } 
        else if (choice == 4) 
        {
            printf("Thank You..");
            exit(0);
        }
        else
        {
        	printf("Invalid Choice.");
		}
    }
    return 0;
}

void enqueue(struct Node** front, struct Node** rear, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (*rear == NULL) 
    {
        *front = *rear = newNode;
    } 
    else 
    {
        (*rear)->next = newNode;
        *rear = newNode;
    }
}

int dequeue(struct Node** front, struct Node** rear) 
{
    if (*front == NULL)
        return -1;
    struct Node* temp = *front;
    int value = temp->data;
    *front = (*front)->next;
    if (*front == NULL)
        *rear = NULL;
    free(temp);
    return value;
}

void display(struct Node* front) 
{
    printf("Queue: ");
    while (front != NULL) 
    {
        printf("%d ", front->data);
        front = front->next;
    }
    printf("\n");
}

