// Single Linked List Operations (SLLO)
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} node_t;

node_t * createEmptyNode();

node_t * createNode(int data);

void addNode(node_t * head, int data);

node_t * getNodeByValue(node_t * head, int data);

node_t * getNodeByPosition(node_t * head, int position);

void destroyLinkedList(node_t ** head_ref);

node_t * removeNodeByPosition(node_t * head, int position);

void updateNodeByPosition(node_t * head, int position, int data);

void updateNodeByValue(node_t * head, int value, int data);

void insertNodeAtPosition(node_t * head, node_t * node, int position);

void replaceNodeAtPosition(node_t * head, int position, node_t * node);

void printLinkedList(node_t * head);