// Doubly Linked List Operations (DLLO)
#include <stdlib.h>
#include <stdio.h>
#include "doubleLLO.h"

dllNode * createEmptyDllNode()
{
    dllNode * node = (dllNode *)malloc(sizeof(dllNode));
    if (node == NULL)
    {
        // If the memory could not be allocated correctly, fail gracefully
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    node->previous = NULL;
    node->next = NULL;
    return node;
}

dllNode * createDllNode(int data)
{
    dllNode * node = createEmptyDllNode();
    node->data = data;
    return node;
}

dllNode * getDllNodeAtPosition(dllNode ** head_ref, int position)
{
    int counter = 0;
    dllNode * current = *head_ref;
    while(counter < position && current != NULL)
    {
        current = current->next;
        counter++;
    }
    if (counter < position)
    {
        printf("There are %d nodes. Cannot get node at position %d.", counter, position);
        return NULL;
    }
    printf("value of node grabbed: %d\n", current->data);
    return current;
}

void printDll(dllNode ** head_ref)
{
    int counter = 0;
    dllNode * current = *head_ref;
    while(current != NULL)
    {
        printf("%d: %d\n", counter++, current->data);
        current = current->next;
    }
}

void addDllNodeToEnd(dllNode ** head_ref, int data)
{
    dllNode * temp = createDllNode(data);
    dllNode * current = *head_ref;
    while(current->next != NULL) current = current->next;
    temp->previous = current;
    current->next = temp;
}

void addDllNodeToStart(dllNode ** head_ref, int data)
{
    dllNode * temp = createDllNode(data);
    temp->next = *head_ref;
    *head_ref= temp;
}

void insertDllNodeAtPosition(dllNode ** head_ref, dllNode * node, int position)
{
    if (position == 0)
    {
        node->next = *head_ref;
        (*head_ref)->previous = node;
        *head_ref = node;
        return;
    }
    dllNode * current = (position == 0 ? getDllNodeAtPosition(head_ref, position) : *head_ref);
    printf("returned node: %d\n", current->data);
    printf("current is the same as head = %d\n", current == *head_ref);
    if (current != NULL)
    {
        node->next = current;
        (current->previous)->next = node;
        current->previous = node;
        current = node;    
    }
}

void insertDllNodeAfterPosition(dllNode ** head_ref, dllNode * node, int position)
{
    dllNode * current = getDllNodeAtPosition(head_ref, position);
    if (current != NULL)
    {
        if (current->next != NULL)
        {
            (current->next)->previous = node;
        }
        node->next = current->next;
        current->next = node;
        node->previous = current;
    }
}

void createDllNodeAtPosition(dllNode ** head_ref, int data, int position)
{
    insertDllNodeAtPosition(head_ref, createDllNode(data), position);
}