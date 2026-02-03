#include <stdio.h>
#define MAX 100

// Structure
typedef struct {
    int data;
    int priority;
} PQ;

// Global queue
PQ pq[MAX];
int size = 0;

// Function prototypes
void insert(int data, int priority);
int deleteAscending();
int deleteDescending();
void display();
void runTestCases();

// Main
int main() {
    runTestCases();
    return 0;
}

// Insert element
void insert(int data, int priority) {
    if (size == MAX) {
        printf("Queue is full\n");
        return;
    }
    pq[size].data = data;
    pq[size].priority = priority;
    size++;
}

// Delete smallest priority
int deleteAscending() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int min = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority < pq[min].priority)
            min = i;
    }

    int value = pq[min].data;
    pq[min] = pq[size - 1];
    size--;
    return value;
}

// Delete largest priority
int deleteDescending() {
    if (size == 0) {
        printf("Queue is empty\n");
        return -1;
    }

    int max = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i].priority > pq[max].priority)
            max = i;
    }

    int value = pq[max].data;
    pq[max] = pq[size - 1];
    size--;
    return value;
}

// Display queue
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Data  Priority\n");
    for (int i = 0; i < size; i++) {
        printf("%d     %d\n", pq[i].data, pq[i].priority);
    }
}

// Predefined test cases
void runTestCases() {
    printf("Inserting elements:\n");
    insert(10, 2);
    insert(20, 1);
    insert(30, 3);
    insert(40, 0);
    display();

    printf("\nDelete Ascending (lowest priority first):\n");
    printf("Deleted: %d\n", deleteAscending());
    printf("Deleted: %d\n", deleteAscending());
    display();

    printf("\nDelete Descending (highest priority first):\n");
    printf("Deleted: %d\n", deleteDescending());
    printf("Deleted: %d\n", deleteDescending());
    display();
}
