#include<stdio.h>
#include<stdlib.h>
#define MAX 10

typedef struct Stack{
    int arr[MAX];
    int top;
} stk;

void push(stk* stk1, int val);
int pop(stk* stk1);
int peek(stk* stk1);
int isFull(stk* stk1);
int isEmpty(stk* stk1);

int main(){
    int ch, val;

    stk* stk1 = (stk *) malloc(sizeof(stk));
    if(stk1 == NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    stk1->top = -1;

    while(1){
        printf("\nMenu\n1.Push\n2.Pop\n3.Peek\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter the number: ");
                scanf("%d",&val);
                push(stk1,val);
                break;

            case 2:
                val = pop(stk1);
                if(val != -1)
                    printf("%d is popped out of the stack\n",val);
                break;

            case 3:
                val = peek(stk1);
                if(val != -1)
                    printf("%d is the top element of the stack\n",val);
                break;

            case 4:
                printf("Exiting the program\n");
                free(stk1);
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(stk* stk1, int val){
    if(isFull(stk1)){
        printf("Stack Overflow\n");
        return;
    }
    stk1->top++;
    stk1->arr[stk1->top] = val;
    printf("Element pushed\n");
}

int pop(stk* stk1){
    if(isEmpty(stk1)){
        printf("Stack Underflow\n");
        return -1;
    }
    int val = stk1->arr[stk1->top];
    stk1->top--;
    return val;
}

int peek(stk* stk1){
    if(isEmpty(stk1)){
        printf("Stack Underflow\n");
        return -1;
    }
    return stk1->arr[stk1->top];
}

int isFull(stk* stk1){
    return stk1->top == MAX - 1;
}

int isEmpty(stk* stk1){
    return stk1->top == -1;
}
