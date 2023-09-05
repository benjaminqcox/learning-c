#include <stdio.h>
#include <stdlib.h>
#include "singleLLO.h"
#include "doubleLLO.h"
#include "circularLLO.h"

void testSll()
{
    // Create root SllNode for a single linked list
    sllNode * root = createSllNode(123);
    for (int i = 25; i < 50; i++)
    {
        // Add SllNodes to the list with values from 25 to 50
        addSllNode(root, i);
    }
    // Print the values before any operations have been performed
    printSll(root);

    // Make the spacing between the before and after changes clear
    printf("END OF BEFORE CHANGES\n\n\nSTART OF AFTER CHANGES\n");

    // Add a SllNode at position 10 to store the value of 55 -> 9: 55
    insertSllNodeAtPosition(root, createSllNode(55), 0);
    // Remove root SllNode (0: 123) -> 0: 25, 1, 26, 2: 28, 3:...
    removeSllNodeByPosition(&root, 0);
    // Remove SllNode at position 3 -> 0: 25, 1, 26, 2: 28, 3:...
    removeSllNodeByPosition(&root, 2);
    // Update SllNode with the value of 33 to store the value 420 -> 8: 420
    updateSllNodeByValue(root, 33, 420);
    // Replace the SllNode at position 5 with a SllNode of value 999 -> 5: 999
    replaceSllNodeAtPosition(&root, 5, createSllNode(999));
    // Update SllNode at position 6 to store the value 150 -> 6: 150
    updateSllNodeByPosition(root, 6, 150);
    // Output these results and confirm they are correct
    printSll(root);


    // Test the output of grabbing specific SllNodes rather than updating root
    printf("SllNode value at position %d: %d\n", 4, getSllNodeByPosition(root, 4)->data);
    printf("SllNode reference by searching for value %d: %p\n", 19, getSllNodeByValue(root, 44));

    // Clear the memory taken up by this linked list
    destroySll(&root);
}

void testDll()
{
    dllNode * root = createDllNode(123);
    for (int i = 0; i < 2; i++)
    {
        addDllNodeToEnd(&root, i);
        
    }
    for (int i = 50; i > 40; i--)
    {
        addDllNodeToStart(&root, i);
    }
    for (int i = 23; i < 33; i++)
    {
        insertDllNodeAtPosition(&root, createDllNode(i), 0);
    }
    printDll(&root);
}

void testCsll()
{
    csllNode * tail = createCsllNode(123);
    for (int i = 0; i < 15; i++)
    {
        addCsllNodeToEnd(&tail, i);
    }
    for (int i = 60; i < 75; i++)
    {
        addCsllNodeToStart(&tail, i);
    }
    printCsll(&tail);
}

int main()
{
    //testSll();
    //testDll();
    testCsll();
    return 0;
}