#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Node {
    int coeff;
    int exp;
    struct Node* next;
} node;

node* createNode(int coeff, int exp);
void insertTerm(node** head, int coeff, int exp);
void displayPolynomial(node* head);
double evaluatePolynomial(node* head, double x);

int main() 
{
    node* poly = NULL;
    int n, coeff, exp, i;
    double x, result;

    printf("Enter number of terms: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
	printf("\n");
    printf("The Polynomial: ");
    displayPolynomial(poly);
    
	printf("\n");
	
    printf("Enter value of x: ");
    scanf("%lf", &x);
    printf("\n");
    
    result = evaluatePolynomial(poly, x);
    printf("Value of polynomial at x = %.2f is: %.2f\n", x, result);
    printf("\n");

    return 0;
}

node* createNode(int coeff, int exp) 
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->coeff = coeff;
    newNode->exp = exp;
    newNode->next = NULL;
    return newNode;
}

void insertTerm(node** head, int coeff, int exp) 
{
    node* temp = *head;
    node* prev = NULL;

    
    while (temp != NULL) 
    {
        if (temp->exp == exp) 
        {
            temp->coeff += coeff; 
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    node* newNode = createNode(coeff, exp);
    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        prev->next = newNode;
    }
}

void displayPolynomial(node* head) 
{
    node* temp = head;
    while (temp != NULL) 
    {
        printf("%d", temp->coeff);
        if (temp->exp != 0)
            printf("x^%d", temp->exp);
        if (temp->next != NULL && temp->next->coeff >= 0)
            printf(" + ");
        else if (temp->next != NULL)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

double evaluatePolynomial(node* head, double x) 
{
    double result = 0.0;
    node* temp = head;
    while (temp != NULL) 
    {
        result += temp->coeff * pow(x, temp->exp);
        temp = temp->next;
    }
    return result;
}
