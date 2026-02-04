#include<stdio.h>
#include<stdlib.h>

typedef struct linkedNode{
	int data;
	struct linkedNode* next;
} node;

void insertEnd(node** head, int val);
void insertBegin(node** head, int val);
int deleteEnd(node** head);
int deleteBegin(node** head);
void display(node** head);

int main(){
	int ch, val;

	node* head = NULL;

	while(1){
		printf("Menu\n1.insertEnd\n2.insertBegin\n3.deleteEnd\n4.deleteBegin\n5.Display\n6.Exit\nEnter your choice: \n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("Enter the element to enter: ");
				scanf("%d",&val);
				insertEnd(&head, val);
				break;
			case 2:
				printf("Enter the element to enter: ");
				scanf("%d",&val);
				insertBegin(&head, val);
				break;
			case 3:
				val = deleteEnd(&head);
				printf("Element at end is: %d",val);
				break;
			case 4:
				val = deleteBegin(&head);
				printf("Element at beginning is: %d",val);
				break;
			case 5:
				display(&head);
				break;
			case 6:
				printf("Exiting");
				exit(0);
				break;
			default:
				printf("Invalid choice !! Enter carefully\n");
				break;
		}
	}
	return 0;
}

void insertEnd(node** head, int val){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = val;
	newNode->next = NULL;
	if (*head == NULL){
		*head = newNode;
		return;
	}
	node* temp = *head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}

void insertBegin(node** head, int val){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->data = val;
	newNode->next = *head;
	*head = newNode;
}
int deleteEnd(node** head){
	node* temp;
	int val;
	if (*head == NULL){
		return -1;
	}
	temp = *head;
	if ((*head)->next == NULL){
		val = temp->data;
		*head = NULL;
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

int deleteBegin(node** head){
	node* temp;
	int val;
	if (*head == NULL){
		return -1;
	}
	temp = *head;
	val = temp->data;
	*head = (*head)->next;
	free(temp);
	return val;
}

void display(node** head){
	if (*head == NULL){
		printf("Linked List is empty\n");
		return;
	}
	node* temp = *head;
	printf("Linked List: ");
	while(temp != NULL){
		printf("%d -> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}
