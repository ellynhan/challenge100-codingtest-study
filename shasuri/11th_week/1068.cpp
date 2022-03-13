#include <iostream>

using namespace std;

struct Node
{
    int nodeNum = -1;
    Node *parent;
    Node *children[50];
    int childNum = 0;
} nodes[50];

int N;
int totalNodeNum = 0;
int restLeafNum = 0;
Node rootNode;

void appendNode(int);
void deleteNode(int);
void printLeafNum(void);
void findLeafNode(Node *);

int main(void)
{

    cin >> N;

    int inputParentNum, deleteNodeNum;

    for (int i = 0; i < N; i++)
    {
        cin >> inputParentNum;
        appendNode(inputParentNum);
    }

    cin >> deleteNodeNum;

    deleteNode(deleteNodeNum);

    printLeafNum();
}

void appendNode(int inputParentNum)
{
    Node *newNode = &nodes[totalNodeNum++];
    newNode->nodeNum = totalNodeNum - 1;

    Node *parentNode =
        (inputParentNum != -1) ? &nodes[inputParentNum] : &rootNode;

    newNode->parent = parentNode;

    parentNode->children[parentNode->childNum++] = newNode;
}

void deleteNode(int deleteNodeNum)
{
    Node *nodeDelete = &nodes[deleteNodeNum];
    Node *parentNode = nodeDelete->parent;
    Node **siblingNode = parentNode->children;

    int parentChildNum = parentNode->childNum;
    int deleteChildNum = -1;

    for (int i = 0; i < parentChildNum; i++)
    {
        if (siblingNode[i]->nodeNum == deleteNodeNum)
        {
            deleteChildNum = i;
            break;
        }
    }

    if (deleteChildNum == -1)
        return;

    for (int i = deleteChildNum; i < parentChildNum - 1; i++)
        siblingNode[i] = siblingNode[i + 1];

    (parentNode->childNum)--;
}

void printLeafNum(void)
{
    findLeafNode(&rootNode);

    cout << restLeafNum << endl;
}

void findLeafNode(Node *parentNode)
{
    if (parentNode->nodeNum != -1 && parentNode->childNum == 0)
    {
        restLeafNum++;
        return;
    }

    for (int i = 0; i < parentNode->childNum; i++)
        findLeafNode(parentNode->children[i]);
}