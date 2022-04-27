#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

struct BinTreeNode
{
    BinTreeNode *leftChild;
    BinTreeNode *rightChild;
} binTree[151];

BinTreeNode rootNode;
int nodeCount;
int structIndex;
char treeStruct[150];

void init(void);
void input(void);
void setupTree(void);
void setupBranch(BinTreeNode *);
void setChildrenNode(BinTreeNode *);
void traverseTree(void);
int postorderTraverse(BinTreeNode *);

int main(void)
{
    int testCase;

    cin >> testCase;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');

    for (int i = 0; i < testCase; i++)
    {
        init();
        input();
        setupTree();
        traverseTree();
    }
}

void init(void)
{
    nodeCount = 0;
    structIndex = 0;
    rootNode.leftChild = nullptr;
    rootNode.rightChild = nullptr;
}

void input(void)
{
    cin.getline(treeStruct,150,'\n');
    // cin >> treeStruct;
}

void setupTree(void)
{
    setupBranch(&rootNode);
}

void setupBranch(BinTreeNode *node)
{
    bool isLeftSet = false;

    while (structIndex < 151 && treeStruct[structIndex] != '\0')
    {
        char thisChar = treeStruct[structIndex];
        structIndex++;
        if (thisChar == '[')
        {
            if (!isLeftSet)
            {
                isLeftSet = true;
                setChildrenNode(node);
                setupBranch(node->leftChild);
            }
            else
                setupBranch(node->rightChild);
        }

        else if (thisChar == ']')
            return;

    }
}

void setChildrenNode(BinTreeNode *parentNode)
{
    parentNode->leftChild = &binTree[nodeCount++];
    parentNode->rightChild = &binTree[nodeCount++];
}

void traverseTree(void)
{
    // cout << (int)pow(2,postorderTraverse(&rootNode)-1) << endl;
    cout << (1 << postorderTraverse(&rootNode)-1) << endl;
}

int postorderTraverse(BinTreeNode *node)
{
    if (node->leftChild != nullptr)
        return max(postorderTraverse(node->leftChild), postorderTraverse(node->rightChild)) + 1;
    else
        return 1;
}
