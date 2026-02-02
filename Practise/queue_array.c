#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX 100

typedef struct Queue{
	int arr[MAX];
	int front;
	int rear;
}Queue;

void enqueue(Queue* que,int val);
int dequeue(Queue* que);
int peek(Queue* que);
bool isFull(Queue*que);
bool isEmpty(Queue* que);

int main(){

	int ch = 0;
	int val = 0;

	Queue* que = (Queue*) malloc(sizeof(Queue));
	que->front = -1;
	que->rear = -1;

	while(1){
		printf("Menu:\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit\nEnter your choice:");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the element to Enqueue: ");
				scanf("%d",&val);
				enqueue(que,val);
				break;
			case 2:
				val = dequeue(que);
				printf("The dequeued element is %d\n",val);
				break;
			case 3:
				val = peek(que);
				printf("The element at rear is %d\n",val);
				break;
			case 4:
				printf("Exiting..\n");
				exit(0);
				break;
			default:
				printf("The choice is invalid. Choose carefully !!\n");
				continue;
		}
	}

	return 0;
}

void enqueue(Queue* que,int val){
	if(isFull(que)){
		printf("Queue Overflow!!\n");
		return;
	}
	if (que->front == -1){
        que->front = 0;
	}
	que->rear++;
	que->arr[que->rear] = val;
	printf("%d is enqueued succesfully.\n",val);
	return;
}
int dequeue(Queue* que){
    int num = 0;
    if(isEmpty(que)){
        printf("Queue Underflow!!\n");
        return -1;
    }

    num = que->arr[que->front];
    que->front++;

    if (que->front > que->rear){
        que->front = -1;
        que->rear = -1;
    }
    return num;
}

int peek(Queue* que){
	int num = 0;
	if(isEmpty(que)){
		printf("Queue Underflow!!\n");
		return -1;
	}
	else{
		num = que->arr[que->front];
		return num;
	}
}
bool isFull(Queue*que){
	if ((que->rear) == MAX - 1){
		return true;
	}
	else
		return false;
}
bool isEmpty(Queue* que){
	if ((que->front == -1)||((que->front) > (que->rear))){
		return true;
	}
	else
		return false;
}