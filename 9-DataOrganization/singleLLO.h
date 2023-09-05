// Single Linked List Operations (SLLO)

typedef struct sllNode
{
    int data;
    struct sllNode *next;
} sllNode;

sllNode * createEmptySllNode();

sllNode * createSllNode(int data);

void addSllNode(sllNode * head, int data);

sllNode * getSllNodeByValue(sllNode * head, int data);

sllNode * getSllNodeByPosition(sllNode * head, int position);

void destroySll(sllNode ** head_ref);

void removeSllNodeByPosition(sllNode ** head, int position);

void updateSllNodeByPosition(sllNode * head, int position, int data);

void updateSllNodeByValue(sllNode * head, int value, int data);

void insertSllNodeAtPosition(sllNode * head, sllNode * SllNode, int position);

void replaceSllNodeAtPosition(sllNode ** head, int position, sllNode * SllNode);

void printSll(sllNode * head);