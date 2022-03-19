#include <stdio.h>
#define MAX_NODE 100000
#define HEAP_EMPTY_CODE 0
using namespace std;

struct HeapNode
{
    int value;
    HeapNode *parent;
    HeapNode *child[2];
} heapNodePool[MAX_NODE];

HeapNode *rootNode;
int nodeCount = 0;
int heapSize = 0;

void command(int);

void heapPush(int);
void firstPush(HeapNode *);
void pushHeapNode(HeapNode *);
HeapNode *getNewNode(int);
HeapNode *findNode(int);
void swapValue(HeapNode *, HeapNode *);
void popPrint(void);
int heapPop(void);
int getHeapEmptyCode(void);
int getRootValue(void);
int getHeapMinValue(void);
HeapNode *getSmallerChild(HeapNode *, HeapNode *);

int main(void)
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(0);

    int N, cmd;
    // cin >> N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        // cin >> cmd;
        scanf("%d", &cmd);
        command(cmd);
    }
}

void command(int cmd)
{
    if (cmd != 0)
        heapPush(cmd);
    else
        popPrint();
}

void heapPush(int newNum)
{
    int newIndex, parentIndex;
    HeapNode *newNode = getNewNode(newNum);

    if (heapSize == 0)
        firstPush(newNode);

    else
        pushHeapNode(newNode);
}

void firstPush(HeapNode *newNode)
{
    rootNode = newNode;
    heapSize++;
    return;
}

void pushHeapNode(HeapNode *newNode)
{
    heapSize++;

    int newIndex = heapSize;
    int parentIndex = newIndex >> 1;
    HeapNode *parentNode = findNode(parentIndex);

    parentNode->child[heapSize & 1] = newNode;
    newNode->parent = parentNode;

    while ((newNode != rootNode) && (newNode->value < parentNode->value))
    {
        // swap only value
        swapValue(newNode, parentNode);

        // refresh nodes
        newNode = parentNode;
        parentNode = newNode->parent;
    }
}

HeapNode *getNewNode(int value)
{
    HeapNode *newNode = &heapNodePool[nodeCount++];
    newNode->value = value;
    newNode->parent = nullptr;
    newNode->child[0] = nullptr;
    newNode->child[1] = nullptr;

    return newNode;
}

HeapNode *findNode(int nodeIndex)
{
    if (nodeIndex == 1)
        return rootNode;
    else
        return findNode(nodeIndex >> 1)->child[nodeIndex & 1];
}

void swapValue(HeapNode *t, HeapNode *u)
{
    int temp;

    temp = t->value;
    t->value = u->value;
    u->value = temp;
}

void popPrint(void)
{
    // cout <<
    //     // "# " <<
    //     heapPop() << endl;
    printf("%d\n", heapPop());
}

int heapPop(void)
{

    if (heapSize == 0)
        return getHeapEmptyCode();

    else if (heapSize == 1)
        return getRootValue();

    else
        return getHeapMinValue();
}

int getHeapEmptyCode(void)
{
    return HEAP_EMPTY_CODE;
}

int getRootValue(void)
{
    heapSize--;
    return rootNode->value;
}

int getHeapMinValue(void)
{
    int minValue = rootNode->value;

    HeapNode *lastNode = findNode(heapSize);
    rootNode->value = lastNode->value;
    lastNode->parent->child[heapSize & 1] = NULL;
    heapSize--;

    HeapNode *currentNode = rootNode;

    HeapNode *leftChild = currentNode->child[0];
    HeapNode *rightChild = currentNode->child[1];

    while (leftChild != NULL)
    {
        HeapNode *smallChild;
        if (rightChild == NULL)
            smallChild = currentNode->child[0];
        else
            smallChild = getSmallerChild(leftChild, rightChild);

        if (currentNode->value < smallChild->value)
            break;

        // swap only value
        swapValue(currentNode, smallChild);

        // refresh nodes
        currentNode = smallChild;
        leftChild = currentNode->child[0];
        rightChild = currentNode->child[1];
    }

    return minValue;
}

HeapNode *getSmallerChild(HeapNode *l, HeapNode *r)
{
    if (l->value < r->value)
        return l;
    else
        return r;
}
