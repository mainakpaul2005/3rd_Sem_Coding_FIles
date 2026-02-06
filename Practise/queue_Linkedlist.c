#include <stdio.h>
#include <stdlib.h>

typedef struct Linkedlist {
    int data;
    struct Linkedlist* next;
} node;

/* Function declarations */
void enqueue(node** front, node** rear, int value);
int dequeue(node** front, node** rear);
void display(node* front);

int main(){
    int ch, val;
    node* front = NULL;
    node* rear  = NULL;

    while (1){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(&front, &rear, val);
                break;

            case 2:
                val = dequeue(&front, &rear);
                if (val == -1)
                    printf("Queue is empty\n");
                else
                    printf("Dequeued element: %d\n", val);
                break;

            case 3:
                display(front);
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

/* Insert at rear */
void enqueue(node** front, node** rear, int value){
    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) return;

    newNode->data = value;
    newNode->next = NULL;

    if (*rear == NULL){
        *front = *rear = newNode;
        return;
    }

    (*rear)->next = newNode;
    *rear = newNode;
}

/* Remove from front */
int dequeue(node** front, node** rear){
    if (*front == NULL){
        return -1;
    }

    node* temp = *front;
    int val = temp->data;

    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
    return val;
}

/* Display queue */
void display(node* front){
    if (front == NULL){
        printf("Queue is empty\n");
        return;
    }

    printf("Queue: ");
    while (front != NULL){
        printf("%d", front->data);
        if (front->next != NULL)
            printf(" -> ");
        front = front->next;
    }
    printf("\n");
}
