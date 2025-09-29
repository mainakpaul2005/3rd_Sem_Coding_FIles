#include <stdio.h>
#include <stdlib.h>
#define SIZE 4

typedef struct Queue {
    int q[SIZE];
    int front;
    int back;
} Q;

int isFull(Q* que);
int isEmpty(Q* que);
void Enqueue(Q* que, int item);
int Dequeue(Q* que);
void display(Q* que);

int main() {
    int ch, item;
    Q* que = (Q*) malloc(sizeof(Q));
    que->front = -1;
    que->back = -1;

    while (1) {
        printf("\nEnter:\n1 for Enqueue\n2 for Dequeue\n3 for Display\n4 for Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if (isFull(que)) {
                    printf("Queue is Full.\n");
                } else {
                    printf("Enter a number: ");
                    scanf("%d", &item);
                    Enqueue(que, item);
                    printf("Enqueued: %d\n", item);
                }
                break;
            case 2:
                if (isEmpty(que)) {
                    printf("Queue is Empty.\n");
                } else {
                    item = Dequeue(que);
                    printf("Dequeued: %d\n", item);
                }
                break;
            case 3:
                display(que);
                break;
            case 4:
                free(que);
                printf("Thanks..\n");
                exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}

int isFull(Q* que) {
    return que->back == SIZE - 1;
}

int isEmpty(Q* que) {
    return que->front == -1 || que->front > que->back;
}

void Enqueue(Q* que, int item) {
    if (que->front == -1)
        que->front = 0;
    que->back++;
    que->q[que->back] = item;
}

int Dequeue(Q* que) {
    int item = que->q[que->front];
    que->front++;
    return item;
}

void display(Q* que) {
    if (isEmpty(que)) {
        printf("Queue is Empty.\n");
    } else {
        printf("Queue elements: ");
        for (int i = que->front; i <= que->back; i++) {
            printf("%d ", que->q[i]);
        }
        printf("\n");
    }
}
