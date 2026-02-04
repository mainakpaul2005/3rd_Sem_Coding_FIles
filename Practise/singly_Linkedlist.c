#include<stdio.h>
#include<stdlib.h>

typedef struct linkedNode{
	int data;
	struct linkedNode*;
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
		printf("Menu\n1.insertEnd\n2.insertBegin\n3.deleteEnd\n4.deleteBegin\n5.Exit\nEnter your choice: \n");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("Enter the element to enter: \n");
				scanf("%d",&val);
				insertEnd(*head, val);
				break;
		}
	}

	return 0;
}