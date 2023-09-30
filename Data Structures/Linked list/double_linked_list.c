#include <stdio.h>
#include <stdlib.h>

// Define datatype for a single node
typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
}Node, *Root;