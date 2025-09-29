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
node* multiplyPolynomial(node* head1, node* head2);
node* createPolynomial(int n);
double evaluatePolynomial(node* head, double x);

int main() 
{
    node* poly1 = NULL;
    node* poly2 = NULL;
    node* product = NULL;
    int n1, n2;
    double x, result;
	
	//The First Polynomial
    printf("Enter number of terms for polynomial 1: ");
    scanf("%d", &n1);
	poly1 = createPolynomial(n1);
    
    //The Second Polynomial
    printf("Enter number of terms for polynomial 2: ");
    scanf("%d", &n2);
    poly2 = createPolynomial(n2);
    
    
    product = multiplyPolynomial(poly1, poly2);
    printf("\nProduct Polynomial: ");
    displayPolynomial(product);
    
    printf("\n");
	
    printf("Enter value of x: ");
    scanf("%lf", &x);
    printf("\n");
    
    result = evaluatePolynomial(product, x);
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
    if (coeff == 0) return; 

    node* newNode = createNode(coeff, exp);

    if (*head == NULL) 
    {
        *head = newNode;
        return;
    }

    node* temp = *head;
    node* prev = NULL;

    while (temp != NULL && temp->exp > exp) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL && temp->exp == exp) 
    {
        temp->coeff += coeff;
        free(newNode);
        if (temp->coeff == 0) 
        {
            if (prev == NULL) 
                *head = temp->next;
            else 
                prev->next = temp->next;
            free(temp);
        }
        return;
    }

    if (prev == NULL) 
    {
        newNode->next = *head;
        *head = newNode;
    } 
    else 
    {
        prev->next = newNode;
        newNode->next = temp;
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

node* multiplyPolynomial(node* head1, node* head2) 
{
    node* result = NULL;
    node* temp1 = head1;
    node* temp2;

    while (temp1 != NULL) 
    {
        temp2 = head2;
        while (temp2 != NULL) 
        {
            int coeff = temp1->coeff * temp2->coeff;
            int exp = temp1->exp + temp2->exp;
            insertTerm(&result, coeff, exp);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return result;
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

node* createPolynomial(int n)
{
	node* poly = NULL;
	int coeff, exp, i;
    for (i = 0; i < n; i++) 
    {
        printf("Enter coefficient and exponent for term %d: ", i + 1);
        scanf("%d %d", &coeff, &exp);
        insertTerm(&poly, coeff, exp);
    }
	printf("\n");
    printf("The Polynomial is: ");
    displayPolynomial(poly);
    return poly;
}
