#include <stdio.h>
#include <stdlib.h>

// Define datatype for a single node
typedef struct Node{
    int data;
    struct Node *next;
}Node;

// Function
Node* makeNode(int data) {
    Node* p = (Node*)malloc(sizeof(Node));
    p->data = data;
    p->next = NULL;
    return p;
}

Node* insertTail(Node* head, int data){
    Node* p = head;
    if (head == NULL){
        return makeNode(data);
    }
    while(p->next != NULL)
        p = p->next;
    Node* q = makeNode(data);
    p->next = q;
    return head;
}

Node* insertHead(Node* head, int data){
    Node* p = makeNode(data);
    if (head == NULL){
        return p;
    }
    p->next = head;
    return p;
}

void showList(Node* head){
    for (Node* p = head; p!= NULL; p=p->next){
        printf("%d ",p->data);
    }
}

int main(){
    Node* head = NULL;
    head = insertTail(head,1);
    head = insertTail(head,2);
    showList(head);
    return 0;
}