// Single Linked List Operations (SLLO)
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#include "singleLLO.h"

sllNode * createEmptySllNode()
{
    // Create a temporary SllNode and allocate it to have memory space equal to that of the sllNode struct memory
    // sllNode -> int data; SllNode * next; -> integer + pointer (integer) -> 8bytes
    sllNode * temp;
    temp = (sllNode*)malloc(sizeof(sllNode));
    if (temp == NULL)
    {
        // If the memory could not be allocated correctly, fail gracefully
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Set the value of the linked SllNode to null rather than a random address
    // This will act as the stop condition in the linked list search
    temp->next = NULL; // Effectively the same as doing (*temp).next = NULL;
    return temp;
}

sllNode * createSllNode(int data)
{
    // Make an empty SllNode and fill in the data
    // Turns a common 2 step functionality into a single step
    sllNode * temp = createEmptySllNode();
    temp->data = data;
    return temp;
}

void addSllNode(sllNode * head, int data)
{
    // Create a SllNode and add it to the end of the linked list
    sllNode * temp = createSllNode(data);
    sllNode * p = head;

    // while there is still another SllNode in the linked list, grab it
    // p is used here so the reference to head is not lost. p and head share
    // the same children references so values updated in p are updated in head
    while (p->next != NULL)
    {
        p = p->next;
    }

    // This will add the SllNode to the end of head
    p->next = temp;
}

sllNode * getSllNodeByValue(sllNode * head, int data)
{
    // Create a copy of head to iterate over
    sllNode * p = head;

    while (p->next != NULL)
    {
        // while there are still SllNodes in the linked list, check if it matches the data argument
        // return this element if it does
        if (p->data == data) return p;
        p = p->next;
    }
    
    // NULL returned here rather than head so the user knows there is no confusion as to why the value does not match
    // (if head was returned, it seems as though the value was found)
    printf("No SllNode found with a value of: %d", data);
    return NULL;
}

sllNode * getSllNodeByPosition(sllNode * head, int position)
{
    int counter = 0;
    sllNode * current = head;

    while (current != NULL)
    {
        // while there are still SllNodes in the linked list check if the counter is the same as the position requested
        // counter increments every time a new SllNode is checked
        if(counter++ == position) return current;
        current = current->next;
    }
    // current == null on the final SllNode, so this may be the SllNode the user was requesting
    if(counter == position) return current;

    // NULL returned here rather than head so the user knows there is no confusion as to why the value does not match
    // (if head was returned, it seems as though the value was found)
    printf("No SllNode found in position: %d\nThere are only %d SllNodes in the linked list.", position, counter);
    return NULL;
}

void destroySll(sllNode ** head_ref)
{
    // Starting with the head reference loop through each of its children
    // for each child store its child and then clear the memory of the parent
    // do this until there are no children left
    sllNode * current = *head_ref;
    sllNode * next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    // set the original memory reference of head to NULL
    *head_ref = NULL;
}

void removeSllNodeByPosition(sllNode ** head, int position)
{
    // if the chosen position to remove is 0, the head is replaced by its child if it has a child
    // if it does not have a child, then the newHead will be set to NULL
    if (position == 0)
    {
        sllNode * origHead = *head;
        *head = (*head)->next;
        free(origHead);
        origHead = NULL;
        if (*head == NULL) printf("You have deleted the root SllNode.");
        return;
    }
    // find the position of the parent to the SllNode we are searching for
    sllNode * previous = getSllNodeByPosition(*head, --position);
    // find the child to the SllNode we are removing
    sllNode * toRemove = previous->next;
    // if the SllNode we are removing has a child, relink it
    if (toRemove->next != NULL)
    {
        // set the child of the SllNode we are removing to the child of the parent of the SllNode we are removing
        previous->next = toRemove->next;
        // clear the memory of the unlinked child
        free(toRemove);
        toRemove = NULL;
    }
}

void updateSllNodeByPosition(sllNode * head, int position, int newData)
{
    // Find the SllNode we want to update based on its position index and change the data stored in it
    sllNode * SllNode = getSllNodeByPosition(head, position);
    SllNode->data = newData;
}

void updateSllNodeByValue(sllNode * head, int data, int newData)
{
    // Find the SllNode we want to update based on its stored value and change the data stored in it
    sllNode * SllNode = getSllNodeByValue(head, data);
    SllNode->data = newData;
}

void insertSllNodeAtPosition(sllNode * head, sllNode * SllNode, int position)
{
    // If the position chosen is 0, the root SllNode just needs to be linked to the SllNode being inserted
    if (position == 0)
    {
        SllNode->next = head;
        return;
    }

    // Get the parent SllNode to the chosen position
    sllNode * shift = getSllNodeByPosition(head, --position);
    if (shift->next != NULL)
    {
        // If the chosen position is not the final SllNode, set its child to the next SllNode
        SllNode->next = shift->next;
    }
    else
    {
        // If the chosen position is the final SllNode, create 
        SllNode->next = createEmptySllNode();
    }
    // set the child of the parent to the chosen SllNode
    shift->next = SllNode;
}

void replaceSllNodeAtPosition(sllNode ** head, int position, sllNode * SllNode)
{
    removeSllNodeByPosition(head, position);
    insertSllNodeAtPosition(*head, SllNode, position);
}

void printSll(sllNode * head)
{
    // Go through each SllNode starting from the root SllNode and print the position index and the value stored in it
    sllNode * current = head;
    int counter = 0;
    while(current != NULL)
    {
        printf("%d: %d\n", counter++, current->data);
        current = current->next;
    }
}