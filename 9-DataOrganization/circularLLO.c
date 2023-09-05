// Single Circularly Linked List Operations (SCLLO)
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "circularLLO.h"

csllNode* createEmptyCsllNode()
{
    // Create a temporary csllNode and allocate it to have memory space equal to that of the csllNode struct memory
    // csllNode -> int data; csllNode* next; -> integer + pointer (integer) -> 8bytes
    csllNode* temp;
    temp = (csllNode*)malloc(sizeof(csllNode));
    if (temp == NULL)
    {
        // If the memory could not be allocated correctly, fail gracefully
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Set the value of the linked csllNode to null rather than a random address
    // This will act as the stop condition in the linked list search
    temp->next = temp; // Effectively the same as doing (*temp).next = NULL;
    return temp;
}

csllNode * createCsllNode(int data)
{
    csllNode * temp = createEmptyCsllNode();
    temp->data = data;
    return temp;
}

void addCsllNodeToStart(csllNode ** tail, int data)
{
    csllNode * node = createCsllNode(data);
    node->next = (*tail)->next;
    (*tail)->next = node;
}

void addCsllNodeToEnd(csllNode ** tail, int data)
{
    csllNode * node = createCsllNode(data);

    node->next = (*tail)->next;
    (*tail)->next = node;
    *tail = node;
}

void printCsll(csllNode ** tail_ref)
{
    int counter = 0;
    csllNode * current = (*tail_ref)->next;
    while(current != *tail_ref)
    {
        printf("%d: %d\n", counter, current->data);
        counter++;
        current = current->next;
    }
}