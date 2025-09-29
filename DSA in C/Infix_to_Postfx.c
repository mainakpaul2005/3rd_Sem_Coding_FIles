#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

typedef struct Stack {
    char stack[SIZE];
    int top;
} stk;

void push(stk* s, char item);
char pop(stk* s);
char peek(stk* s);
int isEmpty(stk* s);
int precedence(char op);
void infixToPostfix(stk* s, char* infix, char* postfix);

int main() 
{
	stk* s = (stk*) malloc(sizeof(stk));
    s->top = -1;
    
    char infix[100], postfix[100];
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    
    infixToPostfix(s,&infix,&postfix);
    
    printf("Postfix Expression: %s\n", postfix);
    
    return 0;
}


void push(stk* s, char item) 
{
    if (s->top >= SIZE - 1) 
	{
        printf("Stack overflow!\n");
        return;
    }
    s->stack[++s->top] = item;
}


char pop(stk* s) 
{
    if (s->top < 0) 
	{
        printf("Stack underflow!\n");
        return -1;
    }
    return s->stack[s->top--];
}


char peek(stk* s) 
{
    if (s->top < 0) return -1;
    return s->stack[s->top];
}

int isEmpty(stk* s) 
{
    return s->top == -1;
}


int precedence(char op) 
{
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}


void infixToPostfix(stk* s,char* infix, char* postfix) 
{
    
    int i = 0, j = 0;
    char ch;
    
    while ((ch = infix[i++]) != '\0') 
	{
        
        if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' ||ch == '9' )  
		{
            postfix[j++] = ch;
        }
        
        else if (ch == '(') 
		{
            push(s, ch);
        }
        
        else if (ch == ')') 
		{
            while (!isEmpty(s) && peek(s) != '(') 
			{
                postfix[j++] = pop(s);
            }
            pop(s); 
        }
        
        else 
		{
            while (!isEmpty(s) && precedence(peek(s)) >= precedence(ch)) 
			{
                postfix[j++] = pop(s);
            }
            push(s, ch);
        }
    }
    
    
    while (!isEmpty(s)) 
	{
        postfix[j++] = pop(s);
    }
    
    postfix[j] = '\0';
}