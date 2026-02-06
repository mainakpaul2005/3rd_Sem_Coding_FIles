#include<stdio.h>
#include<stdlib.h>

typedef struct linkedNode{
	int data;
	struct linkedNode* next;
} node;

void push(node** top, int val); // insert at end
int pop(node** top); // delete at end 
void display(node** top); 

int main(){
    int ch, val;
    node* top = NULL;

    while(1){
        printf("Menu\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter your choice:\n");
        scanf("%d",&ch);

        switch(ch){
            case 1:
                printf("Enter element: ");
                scanf("%d",&val);
                push(&top, val);
                break;
            case 2:
                val = pop(&top);
                if (val == -1)
                    printf("Stack is empty\n");
                else
                    printf("Popped: %d\n", val);
                break;
            case 3:
                display(&top);
                break;
            case 4:
                exit(0);
        }
    }
}


void push(node** top, int val){
    if (top == NULL) return;

    node* newNode = malloc(sizeof(node));
    if (newNode == NULL) return;

    newNode->data = val;
    newNode->next = NULL;

    if (*top == NULL){
        *top = newNode;
        return;
    }

    node* temp = *top;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}

int pop(node** top){
	node* temp = *top;
	int val = 0;
	if (*top == NULL){
		return -1;
	}
	temp = *top;
	if ((*top)->next == NULL){
		val = temp->data;
		*top = NULL;
		free(temp);
		return val;
	}
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	val = temp->next->data;
	free(temp->next);
	temp->next = NULL;
	return val;

}
void display(node** top){
    if (top == NULL || *top == NULL){
        printf("List is empty\n");
        return;
    }

    node* temp = *top;
    printf("List is: ");
    while (temp != NULL){
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" -> ");
        temp = temp->next;
    }
    printf("\n");
}
