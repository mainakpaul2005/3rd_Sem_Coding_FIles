#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};

void insertBegin(struct Node** head, int value);
void insertEnd(struct Node** head, int value);
void insertAtPos(struct Node** head, int value, int pos);
void insertAfterValue(struct Node** head, int value, int after);
void insertBeforeValue(struct Node** head, int value, int before);
void deleteBegin(struct Node** head);
void deleteEnd(struct Node** head);
void deleteAtPos(struct Node** head, int pos);
void deleteByValue(struct Node** head, int value);
void deleteList(struct Node** head);
int searchByValue(struct Node* head, int value);
int searchByPos(struct Node* head, int pos);
void display(struct Node* head);
int countNodes(struct Node* head);
void reverseIterative(struct Node** head);
struct Node* reverseRecursive(struct Node* head);
void sortAscending(struct Node** head);
void sortDescending(struct Node** head);
int getNthFromStart(struct Node* head, int n);
int getNthFromEnd(struct Node* head, int n);
int findMiddle(struct Node* head);
void swapNodes(struct Node** head, int val1, int val2);
void removeDuplicates(struct Node* head);

int main() 
{
	struct Node* head = NULL;
	int choice = 0, value, pos, after, before, n, val1, val2;

	while (choice != 22) 
	{
		printf("\n1.Insert Begin\n2.Insert End\n3.Insert At Pos\n4.Insert After Value\n5.Insert Before Value\n6.Delete Begin\n7.Delete End\n8.Delete At Pos\n9.Delete By Value\n10.Delete Entire List\n11.Search By Value\n12.Search By Position\n13.Display\n14.Count Nodes\n15.Reverse Iterative\n16.Reverse Recursive\n17.Sort Asc\n18.Sort Desc\n19.Get Nth From Start\n20.Get Nth From End\n21.Find Middle\n22.Swap Nodes\n23.Remove Duplicates\n24.Exit\nEnter choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				printf("Enter value: ");
				scanf("%d", &value);
				insertBegin(&head, value);
				break;
			case 2:
				printf("Enter value: ");
				scanf("%d", &value);
				insertEnd(&head, value);
				break;
			case 3:
				printf("Enter value and position: ");
				scanf("%d %d", &value, &pos);
				insertAtPos(&head, value, pos);
				break;
			case 4:
				printf("Enter value and after value: ");
				scanf("%d %d", &value, &after);
				insertAfterValue(&head, value, after);
				break;
			case 5:
				printf("Enter value and before value: ");
				scanf("%d %d", &value, &before);
				insertBeforeValue(&head, value, before);
				break;
			case 6:
				deleteBegin(&head);
				break;
			case 7:
				deleteEnd(&head);
				break;
			case 8:
				printf("Enter position: ");
				scanf("%d", &pos);
				deleteAtPos(&head, pos);
				break;
			case 9:
				printf("Enter value: ");
				scanf("%d", &value);
				deleteByValue(&head, value);
				break;
			case 10:
				deleteList(&head);
				break;
			case 11:
				printf("Enter value: ");
				scanf("%d", &value);
				pos = searchByValue(head, value);
				if (pos != -1) printf("Found at position %d\n", pos);
				else printf("Not found\n");
				break;
			case 12:
				printf("Enter position: ");
				scanf("%d", &pos);
				value = searchByPos(head, pos);
				if (value != -1) printf("Value at position %d is %d\n", pos, value);
				else printf("Invalid position\n");
				break;
			case 13:
				display(head);
				break;
			case 14:
				printf("Count: %d\n", countNodes(head));
				break;
			case 15:
				reverseIterative(&head);
				break;
			case 16:
				head = reverseRecursive(head);
				break;
			case 17:
				sortAscending(&head);
				break;
			case 18:
				sortDescending(&head);
				break;
			case 19:
				printf("Enter n: ");
				scanf("%d", &n);
				value = getNthFromStart(head, n);
				if (value != -1) printf("Value: %d\n", value);
				else printf("Invalid position\n");
				break;
			case 20:
				printf("Enter n: ");
				scanf("%d", &n);
				value = getNthFromEnd(head, n);
				if (value != -1) printf("Value: %d\n", value);
				else printf("Invalid position\n");
				break;
			case 21:
				value = findMiddle(head);
				if (value != -1) printf("Middle: %d\n", value);
				else printf("List empty\n");
				break;
			case 22:
				printf("Enter two values to swap: ");
				scanf("%d %d", &val1, &val2);
				swapNodes(&head, val1, val2);
				break;
			case 23:
				removeDuplicates(head);
				break;
			case 24:
				break;
			default:
				printf("Invalid choice\n");
		}
	}
	return 0;
}


void insertBegin(struct Node** head, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = *head;
	*head = newNode;
}
void insertEnd(struct Node** head, int value) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = NULL;
	if (*head == NULL) {
		*head = newNode;
		return;
	}
	struct Node* temp = *head;
	while (temp->next) temp = temp->next;
	temp->next = newNode;
}
void insertAtPos(struct Node** head, int value, int pos) {
	if (pos <= 0) return;
	if (pos == 1) {
		insertBegin(head, value);
		return;
	}
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	struct Node* temp = *head;
	for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
	if (!temp) return;
	newNode->next = temp->next;
	temp->next = newNode;
}
void insertAfterValue(struct Node** head, int value, int after) {
	struct Node* temp = *head;
	while (temp && temp->data != after) temp = temp->next;
	if (!temp) return;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = temp->next;
	temp->next = newNode;
}
void insertBeforeValue(struct Node** head, int value, int before) {
	if (*head == NULL) return;
	if ((*head)->data == before) {
		insertBegin(head, value);
		return;
	}
	struct Node* temp = *head;
	while (temp->next && temp->next->data != before) temp = temp->next;
	if (!temp->next) return;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	newNode->next = temp->next;
	temp->next = newNode;
}
void deleteBegin(struct Node** head) {
	if (*head == NULL) return;
	struct Node* temp = *head;
	*head = (*head)->next;
	free(temp);
}
void deleteEnd(struct Node** head) {
	if (*head == NULL) return;
	if ((*head)->next == NULL) {
		free(*head);
		*head = NULL;
		return;
	}
	struct Node* temp = *head;
	while (temp->next->next) temp = temp->next;
	free(temp->next);
	temp->next = NULL;
}
void deleteAtPos(struct Node** head, int pos) {
	if (pos <= 0 || *head == NULL) return;
	if (pos == 1) {
		deleteBegin(head);
		return;
	}
	struct Node* temp = *head;
	for (int i = 1; temp && i < pos - 1; i++) temp = temp->next;
	if (!temp || !temp->next) return;
	struct Node* del = temp->next;
	temp->next = del->next;
	free(del);
}
void deleteByValue(struct Node** head, int value) {
	if (*head == NULL) return;
	if ((*head)->data == value) {
		deleteBegin(head);
		return;
	}
	struct Node* temp = *head;
	while (temp->next && temp->next->data != value) temp = temp->next;
	if (!temp->next) return;
	struct Node* del = temp->next;
	temp->next = del->next;
	free(del);
}
void deleteList(struct Node** head) {
	while (*head) deleteBegin(head);
}
int searchByValue(struct Node* head, int value) {
	int pos = 1;
	while (head) {
		if (head->data == value) return pos;
		head = head->next;
		pos++;
	}
	return -1;
}
int searchByPos(struct Node* head, int pos) {
	int i = 1;
	while (head) {
		if (i == pos) return head->data;
		head = head->next;
		i++;
	}
	return -1;
}
void display(struct Node* head) {
	if (!head) {
		printf("List empty\n");
		return;
	}
	while (head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
int countNodes(struct Node* head) {
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}
void reverseIterative(struct Node** head) {
	struct Node *prev = NULL, *curr = *head, *next = NULL;
	while (curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}
struct Node* reverseRecursive(struct Node* head) {
	if (head == NULL || head->next == NULL) return head;
	struct Node* rest = reverseRecursive(head->next);
	head->next->next = head;
	head->next = NULL;
	return rest;
}
void sortAscending(struct Node** head) {
	if (*head == NULL) return;
	struct Node *i, *j;
	int temp;
	for (i = *head; i && i->next; i = i->next) {
		for (j = i->next; j; j = j->next) {
			if (i->data > j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}
void sortDescending(struct Node** head) {
	if (*head == NULL) return;
	struct Node *i, *j;
	int temp;
	for (i = *head; i && i->next; i = i->next) {
		for (j = i->next; j; j = j->next) {
			if (i->data < j->data) {
				temp = i->data;
				i->data = j->data;
				j->data = temp;
			}
		}
	}
}
int getNthFromStart(struct Node* head, int n) {
	int i = 1;
	while (head) {
		if (i == n) return head->data;
		head = head->next;
		i++;
	}
	return -1;
}
int getNthFromEnd(struct Node* head, int n) {
	int len = countNodes(head);
	if (n > len || n <= 0) return -1;
	return getNthFromStart(head, len - n + 1);
}
int findMiddle(struct Node* head) {
	if (!head) return -1;
	struct Node *slow = head, *fast = head;
	while (fast && fast->next) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow->data;
}
void swapNodes(struct Node** head, int val1, int val2) {
	if (val1 == val2) return;
	struct Node *prev1 = NULL, *curr1 = *head;
	while (curr1 && curr1->data != val1) {
		prev1 = curr1;
		curr1 = curr1->next;
	}
	struct Node *prev2 = NULL, *curr2 = *head;
	while (curr2 && curr2->data != val2) {
		prev2 = curr2;
		curr2 = curr2->next;
	}
	if (!curr1 || !curr2) return;
	if (prev1) prev1->next = curr2; else *head = curr2;
	if (prev2) prev2->next = curr1; else *head = curr1;
	struct Node* temp = curr1->next;
	curr1->next = curr2->next;
	curr2->next = temp;
}
void removeDuplicates(struct Node* head) {
	struct Node *ptr1, *ptr2, *dup;
	ptr1 = head;
	while (ptr1 && ptr1->next) {
		ptr2 = ptr1;
		while (ptr2->next) {
			if (ptr1->data == ptr2->next->data) {
				dup = ptr2->next;
				ptr2->next = ptr2->next->next;
				free(dup);
			} else {
				ptr2 = ptr2->next;
			}
		}
		ptr1 = ptr1->next;
	}
}
