#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void push(struct Node** top, int value); 
int pop(struct Node** top);
int peek(struct Node** top);
void display(struct Node* top);

int main() 
{
    struct Node* top = NULL;
    int choice = 0, value;
    
    while (1) 
    {
    	printf("Stack Using Linked-List: \n");
    	printf("------------------------");
        printf("\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        if (choice == 1) 
        {
            printf("Enter value: ");
            scanf("%d", &value);
            push(&top, value);
        } 
        else if (choice == 2) 
        {
            if (top == NULL)
                printf("Stack Underflow\n");
            else
                printf("Popped: %d\n", pop(&top));
        } 
        else if (choice == 3) 
        {
            if (top == NULL)
                printf("Stack is empty\n");
            else
                display(top);
        } 
        else if(choice == 4)
        {
        	printf("Thank You..");
        	exit(0);
		}
        else 
        {
            printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(struct Node** top, int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct Node** top) 
{	
    if (*top == NULL)
        return -1;
    struct Node* temp = *top;
    int value = temp->data;
    *top = (*top)->next;
    free(temp);
    return value;
}

int peek(struct Node** top) 
{
    if (*top == NULL)
        return -1;
    struct Node* temp = *top;
    int value = temp->data;
    return value;
}

void display(struct Node* top) 
{
    printf("Stack: ");
    while (top != NULL) 
    {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
