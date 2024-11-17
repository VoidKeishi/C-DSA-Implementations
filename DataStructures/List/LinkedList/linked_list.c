#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initList(LinkedList* list) {
    list->head = NULL;
}

void insertAtBeginning(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* searchNode(struct LinkedList* list, int key){
    // Todo
}

void displayList(LinkedList* list) {
    // Todo
}

void reverseList(LinkedList* list) {
    // Todo
}

void freeNode(Node* node) {
    free(node);
}

void freeList(LinkedList* list) {
    Node* temp = list->head;
    Node* next = NULL;
    while (temp != NULL) {
        next = temp->next;
        freeNode(temp);
        temp = next;
    }
    list->head = NULL;
}

void deleteNode(LinkedList* list, int key) {
    Node* temp = list->head;
    Node* prev = NULL;
    // If the head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        list->head = temp->next;
        free(temp);
        return;
    }
    // Skip to the node to be deleted
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    // If the key was not present in the list, the temp pointer will be NULL
    if (temp == NULL) {
        return;
    }
    // If the key was found, previous node's next should point to the next node of the node to be deleted
    prev->next = temp->next;
    free(temp);
}



int main(){
    // Example usage
    // Create a new node
    Node* a = createNode(5);
    // Initialize a linked list
    LinkedList* b = (LinkedList*)malloc(sizeof(LinkedList));
    initList(b);
    // Insert a node at the beginning
    insertAtBeginning(b, 10);
    // Insert a node at the end
    // Todo
}
