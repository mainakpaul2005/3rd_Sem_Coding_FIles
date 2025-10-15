#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100
#define FILE_NAME "directory.txt"

typedef struct Contact {
    char name[50];
    char phone[15];
    struct Contact* next;
} Contact;

Contact* hashTable[SIZE];

// -------------------- HASH FUNCTION --------------------
unsigned int hash(char *name) {
    unsigned int hash = 0;
    while (*name)
        hash = (hash + *name++) % SIZE;
    return hash;
}

// -------------------- INSERT --------------------
void insert(char *name, char *phone) {
    unsigned int index = hash(name);
    Contact* newContact = malloc(sizeof(Contact));
    strcpy(newContact->name, name);
    strcpy(newContact->phone, phone);
    newContact->next = hashTable[index];
    hashTable[index] = newContact;
    printf("Contact added: %s - %s\n", name, phone);
}

// -------------------- SEARCH --------------------
void search(char *name) {
    unsigned int index = hash(name);
    Contact* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            printf("Found: %s - %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

// -------------------- DELETE --------------------
void delete(char *name) {
    unsigned int index = hash(name);
    Contact *temp = hashTable[index], *prev = NULL;

    while (temp) {
        if (strcmp(temp->name, name) == 0) {
            if (prev) prev->next = temp->next;
            else hashTable[index] = temp->next;
            free(temp);
            printf("Contact deleted.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Contact not found.\n");
}

// -------------------- SAVE TO FILE --------------------
void saveToFile() {
    FILE *fp = fopen(FILE_NAME, "w");
    if (!fp) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < SIZE; i++) {
        Contact *temp = hashTable[i];
        while (temp) {
            fprintf(fp, "%s %s\n", temp->name, temp->phone);
            temp = temp->next;
        }
    }
    fclose(fp);
}

// -------------------- LOAD FROM FILE --------------------
void loadFromFile() {
    FILE *fp = fopen(FILE_NAME, "r");
    if (!fp) return; // No file yet, skip

    char name[50], phone[15];
    while (fscanf(fp, "%s %s", name, phone) != EOF) {
        insert(name, phone);
    }
    fclose(fp);
}

// -------------------- MAIN --------------------
int main() {
    int choice;
    char name[50], phone[15];

    loadFromFile(); // Load contacts at startup
    printf("Mini Telephone Directory (Persistent)\n");

    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone: ");
                scanf("%s", phone);
                insert(name, phone);
                saveToFile();
                break;
            case 2:
                printf("Enter name to search: ");
                scanf("%s", name);
                search(name);
                break;
            case 3:
                printf("Enter name to delete: ");
                scanf("%s", name);
                delete(name);
                saveToFile();
                break;
            case 4:
                saveToFile();
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}
