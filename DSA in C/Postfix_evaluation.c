#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 100


void push(int *s, int *top, int item);
int pop(int *s, int *top);

int main() 
{
    char pofx[SIZE], ch;
    int i = 0, op1, op2, result;
    int s[SIZE], top = -1;

    printf("\nEnter the postfix expression: ");
    scanf("%s", pofx);

    while ((ch = pofx[i++]) != '\0') 
	{
        if (isdigit(ch)) 
		{
            push(s, &top, ch - '0');   
        } 
		else 
		{
            op2 = pop(s, &top);
            op1 = pop(s, &top);
            switch (ch) 
			{
                case '+': push(s, &top, op1 + op2); break;
                case '-': push(s, &top, op1 - op2); break;
                case '*': push(s, &top, op1 * op2); break;
                case '/':
                    if (op2 == 0)
					{
                        printf("Error: Division by zero\n");
                        return 1;
                    }
                    push(s, &top, op1 / op2);
                    break;
                case '^': push(s, &top, (int)pow(op1, op2)); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 1;
            }
        }
    }
    result = pop(s, &top);
    printf("\nResult after evaluation: %d\n", result);

    return 0;
}


void push(int *s, int *top, int item) 
{
    if (*top >= SIZE - 1) 
	{
        printf("Stack Overflow\n");
        exit(1);
    }
    s[++(*top)] = item;
}

int pop(int *s, int *top) 
{
    if (*top < 0) 
	{
        printf("Stack Underflow\n");
        exit(1);
    }
    return s[(*top)--];
}
