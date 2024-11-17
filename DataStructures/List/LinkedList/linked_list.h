#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Linked list structure
struct LinkedList {
    struct Node* head;
};

// Function to create a new node
struct Node* createNode(int data);

// Function to initialize a linked list
void initList(struct LinkedList* list);

// Function to insert a node at the beginning
void insertAtBeginning(struct LinkedList* list, int data);

// Function to insert a node at the end
void insertAtEnd(struct LinkedList* list, int data);

// Function to delete a node
void deleteNode(struct LinkedList* list, int key);

// Function to search for a node
struct Node* searchNode(struct LinkedList* list, int key);

// Function to display the linked list
void displayList(struct LinkedList* list);

// Function to reverse the linked list
void reverseList(struct LinkedList* list);

// Function to free the memory allocated for the linked list
void freeList(struct LinkedList* list);

#endif // LINKED_LIST_H