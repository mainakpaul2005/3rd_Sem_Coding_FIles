#include<stdio.h>
#include<stdlib.h>
#define SIZE 4

typedef struct Stack {
    int stack[SIZE];
    int size;
} stk;

void push(stk* s1, int item);

int pop(stk* s1, int item);

int peek(stk* s1, int item);

void display(stk* s1);

int main() 
{
    int ch, item = 0;
    stk* s1 = (stk*) malloc(sizeof(stk));
    s1->size = -1;

    while(1) 
	{
        printf("Enter:\n1 for push()\n2 for pop()\n3 for peek()\n4 for display()\n5 for exit:\n");
        scanf("%d", &ch);

        switch(ch) 
		{
            case 1:
                printf("Enter a number: ");
                scanf("%d", &item);
                push(s1, item);
                printf("The pushed element is: %d\n", item);
                break;
            case 2:
                item = pop(s1, item);
                if (item != -1)
                    printf("The popped element is: %d\n", item);
                break;
            case 3:
                item = peek(s1, item);
                if (item != -1)
                    printf("The top element is: %d\n", item);
                break;
			case 4:
    			display(s1);
    			break;
			case 5:
    			free(s1); 
    			printf("Thanks..\n");
    			exit(0);
            default:
                printf("Invalid Choice.\n");
        }
    }

    return 0;
}

void push(stk* s1, int item) 
{
    if (s1->size >= SIZE - 1) 
	{
        printf("Stack overflow!\n");
        return;
    }
    s1->stack[++s1->size] = item;
}

int pop(stk* s1, int item) 
{
    if (s1->size < 0) 
	{
        printf("Stack is empty\n");
        return -1;
    }
    return s1->stack[s1->size--];
}

int peek(stk* s1, int item) 
{
    if (s1->size < 0) 
	{
        printf("Stack is empty!\n");
        return -1;
    }
    return s1->stack[s1->size];
}

void display(stk* s1)
{
    if (s1->size < 0) {
        printf("Stack is empty!\n");
        return;
        
    }
    printf("Stack elements:\n");
    for (int i = s1->size; i >= 0; i--) {
        printf("%d\n", s1->stack[i]);
    }
}
