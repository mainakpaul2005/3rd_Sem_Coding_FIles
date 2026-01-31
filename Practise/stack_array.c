#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Stack{
	int arr[MAX];
	int top;
}stk;

void push(stk* stk1, int val);
int pop(stk* stk1);
int peek(stk* stk1);
int isFull(stk* stk1);
int isEmpty(stk* stk1);

int main(){
	int i, n, ch, val;

	stk* stk1 = (stk *) malloc(sizeof(stk));
	stk1->top = -1;
	

	while(1){
		printf("Menu\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
		printf("Enter your choice:");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("Enter the number: ");
				scanf("%d",&val);
				if(isFull == 1){
					printf("Stack Overflow!!\n");
				}
				else{
					push(*stk,val);
					printf("The element has been pushed to the stack.\n");
				}
			case 2:

		}

	}
	return 0;
}