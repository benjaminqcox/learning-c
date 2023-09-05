// Doubly Linked List Operations (DLLO)

typedef struct dllNode
{
    int data;
    struct dllNode *previous;
    struct dllNode *next;
} dllNode;

dllNode * createEmptyDllNode();

dllNode * createDllNode(int data);

dllNode * getDllNodeAtPosition(dllNode ** head_ref, int position);

void printDll(dllNode ** head_ref);

void addDllNodeToEnd(dllNode ** head_ref, int data);

void addDllNodeToStart(dllNode ** head_ref, int data);

void insertDllNodeAtPosition(dllNode ** head_ref, dllNode * node, int position);

void insertDllNodeAfterPosition(dllNode ** head_ref, dllNode * node, int position);

void createDllNodeAtPosition(dllNode ** head_ref, int data, int position);