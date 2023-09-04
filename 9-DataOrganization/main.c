#include "singleLLO.h"

int main()
{
    // Create root node for a single linked list
    node_t * root = createNode(123);
    for (int i = 25; i < 50; i++)
    {
        // Add nodes to the list with values from 25 to 50
        addNode(root, i);
    }
    // Print the values before any operations have been performed
    printLinkedList(root);

    // Make the spacing between the before and after changes clear
    printf("END OF BEFORE CHANGES\n\n\nSTART OF AFTER CHANGES\n");

    // Add a node at position 10 to store the value of 55 -> 9: 55
    insertNodeAtPosition(root, createNode(55), 10);
    // Remove node at position 3 -> 0: 25, 1, 26, 2: 28, 3:...
    // The root node is returned here to account for if the user chooses to remove node 0
    root = removeNodeByPosition(root, 3);
    // Update node with the value of 33 to store the value 420 -> 8: 420
    updateNodeByValue(root, 33, 420);
    // Replace the node at position 5 with a node of value 999 -> 5: 999
    replaceNodeAtPosition(root, 5, createNode(999));
    // Update node at position 6 to store the value 150 -> 6: 150
    updateNodeByPosition(root, 6, 150);
    // Output these results and confirm they are correct
    printLinkedList(root);

    // Test the output of grabbing specific nodes rather than updating root
    printf("Node value at position %d: %d\n", 4, getNodeByPosition(root, 4)->data);
    printf("Node reference by searching for value %d: %p\n", 19, getNodeByValue(root, 44));

    // Clear the memory taken up by this linked list
    destroyLinkedList(&root);
    
    return 0;
}