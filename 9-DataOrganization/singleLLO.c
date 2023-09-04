// Single Linked List Operations (SLLO)
#include "singleLLO.h"

node_t * createEmptyNode()
{
    // Create a temporary node and allocate it to have memory space equal to that of the node_t struct memory
    // node_t -> int data; node * next; -> integer + pointer (integer) -> 8bytes
    node_t * temp;
    temp = (node_t*)malloc(sizeof(node_t));
    if (temp == NULL)
    {
        // If the memory could not be allocated correctly, fail gracefully
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    // Set the value of the linked node to null rather than a random address
    // This will act as the stop condition in the linked list search
    temp->next = NULL; // Effectively the same as doing (*temp).next = NULL;
    return temp;
}

node_t * createNode(int data)
{
    // Make an empty node and fill in the data
    // Turns a common 2 step functionality into a single step
    node_t * temp = createEmptyNode();
    temp->data = data;
    return temp;
}

void addNode(node_t * head, int data)
{
    // Create a node and add it to the end of the linked list
    node_t * temp = createNode(data);
    node_t * p = head;

    // while there is still another node in the linked list, grab it
    // p is used here so the reference to head is not lost. p and head share
    // the same children references so values updated in p are updated in head
    while (p->next != NULL)
    {
        p = p->next;
    }

    // This will add the node to the end of head
    p->next = temp;
}

node_t * getNodeByValue(node_t * head, int data)
{
    // Create a copy of head to iterate over
    node_t * p = head;

    while (p->next != NULL)
    {
        // while there are still nodes in the linked list, check if it matches the data argument
        // return this element if it does
        if (p->data == data) return p;
        p = p->next;
    }
    
    // NULL returned here rather than head so the user knows there is no confusion as to why the value does not match
    // (if head was returned, it seems as though the value was found)
    printf("No node found with a value of: %d", data);
    return NULL;
}

node_t * getNodeByPosition(node_t * head, int position)
{
    int counter = 0;
    node_t * current = head;

    while (current != NULL)
    {
        // while there are still nodes in the linked list check if the counter is the same as the position requested
        // counter increments every time a new node is checked
        if(counter++ == position) return current;
        current = current->next;
    }
    // current == null on the final node, so this may be the node the user was requesting
    if(counter == position) return current;

    // NULL returned here rather than head so the user knows there is no confusion as to why the value does not match
    // (if head was returned, it seems as though the value was found)
    printf("No node found in position: %d\nThere are only %d nodes in the linked list.", position, counter);
    return NULL;
}

void destroyLinkedList(node_t ** head_ref)
{
    // Starting with the head reference loop through each of its children
    // for each child store its child and then clear the memory of the parent
    // do this until there are no children left
    node_t * current = *head_ref;
    node_t * next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    // set the original memory reference of head to NULL
    *head_ref = NULL;
}

node_t * removeNodeByPosition(node_t * head, int position)
{
    // if the chosen position to remove is 0, the head is replaced by its child if it has a child
    // if it does not have a child, then the newHead will be set to NULL and this is returned
    if (position == 0)
    {
        node_t * newHead = head->next;
        free(head);
        head = NULL;
        if (newHead == NULL) printf("You have deleted the root node, NULL will be returned.");
        return newHead;
    }
    // find the position of the parent to the node we are searching for
    node_t * previous = getNodeByPosition(head, --position);
    // find the child to the node we are removing
    node_t * toRemove = previous->next;
    // if the node we are removing has a child, relink it
    if (toRemove->next != NULL)
    {
        // set the child of the node we are removing to the child of the parent of the node we are removing
        previous->next = toRemove->next;
        // clear the memory of the unlinked child
        free(toRemove);
        toRemove = NULL;
    }
    return head;
}

void updateNodeByPosition(node_t * head, int position, int newData)
{
    // Find the node we want to update based on its position index and change the data stored in it
    node_t * node = getNodeByPosition(head, position);
    node->data = newData;
}

void updateNodeByValue(node_t * head, int data, int newData)
{
    // Find the node we want to update based on its stored value and change the data stored in it
    node_t * node = getNodeByValue(head, data);
    node->data = newData;
}

void insertNodeAtPosition(node_t * head, node_t * node, int position)
{
    // If the position chosen is 0, the root node just needs to be linked to the node being inserted
    if (position == 0)
    {
        node->next = head;
        return;
    }

    // Get the parent node to the chosen position
    node_t * shift = getNodeByPosition(head, --position);
    // Make a copy of the chosen node
    node_t * temp = shift->next;
    if (temp->next != NULL)
    {
        // If the chosen position is not the final node, set its child to the next node
        node->next = temp->next;
    }
    else
    {
        // If the chosen position is the final node, create 
        node->next = createEmptyNode();
    }
    // set the child of the parent to the chosen node
    shift->next = node;
}

void replaceNodeAtPosition(node_t * head, int position, node_t * node)
{
    removeNodeByPosition(head, position);
    insertNodeAtPosition(head, node, position);
}

void printLinkedList(node_t * head)
{
    // Go through each node starting from the root node and print the position index and the value stored in it
    node_t * current = head;
    int counter = 0;
    while(current != NULL)
    {
        printf("%d: %d\n", counter++, current->data);
        current = current->next;
    }
}