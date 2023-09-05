// Single Circularly Linked List Operations (SCLLO)
typedef struct csllNode
{
    int data;
    struct csllNode*next;
} csllNode;

csllNode* createEmptyCsllNode();

csllNode* createCsllNode(int data);

void addCsllNodeToStart(csllNode ** tail, int data);

void addCsllNodeToEnd(csllNode ** tail, int data);

void printCsll(csllNode ** tail_ref);