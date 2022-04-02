#include <iostream>
#define MAX_NODE 20
using namespace std;

struct TreeNode
{
    int parentNum;
    int childNum;
    TreeNode *children[MAX_NODE - 1];
    bool generated;
    bool visited;
} treeNodes[MAX_NODE];

bool endFlag = false;
int edgeCnt;
int caseNum = 0;

void input(void);
void endProcess(void);
void endTestCase(void);
void addEdge(int, int);
void treeInit(void);
void printResult(void);
bool isTree(void);
bool isCycle(TreeNode *);
bool dfs(TreeNode *);

int main(void)
{
    treeInit();

    while (!endFlag)
        input();
}

void treeInit(void)
{
    edgeCnt = 0;
    for (int i = 0; i < MAX_NODE; i++)
    {
        treeNodes[i].parentNum = 0;
        treeNodes[i].childNum = 0;
        treeNodes[i].generated = false;
        treeNodes[i].visited = false;
    }
}

void input(void)
{
    int u, v;

    cin >> u >> v;

    if (u < 0 && v < 0)
    {
        endProcess();
        return;
    }

    if (u == 0 && v == 0)
    {
        endTestCase();
        return;
    }

    addEdge(u, v);

    return;
}

void endProcess(void)
{
    endFlag = true;
    return;
}

void endTestCase(void)
{
    printResult();
    treeInit();
    return;
}

void addEdge(int u, int v)
{
    edgeCnt++;

    treeNodes[u].generated = true;
    treeNodes[v].generated = true;

    treeNodes[u].children[treeNodes[u].childNum++] = &treeNodes[v];
    treeNodes[v].parentNum++;

    return;
}

void printResult(void)
{
    caseNum++;
    cout << "Case " << caseNum << " is";

    if (!isTree())
        cout << " not";

    cout << " a tree." << endl;
    return;
}

bool isTree(void)
{
    if (edgeCnt == 0)
        return true;

    bool rootNodeFindFlag = false;
    TreeNode *rootNode = nullptr;

    for (int i = 0; i < MAX_NODE; i++)
    {
        if (!treeNodes[i].generated)
            continue;

        if (treeNodes[i].parentNum > 1)
            return false;

        if (treeNodes[i].parentNum == 0)
            if (!rootNodeFindFlag)
            {
                rootNode = &treeNodes[i];
                rootNodeFindFlag = true;
            }
            else
                return false;
    }

    if (isCycle(rootNode))
        return false;

    return true;
}

bool isCycle(TreeNode *rootNode)
{
    if (rootNode == nullptr)
    {
        for (int i = 0; i < MAX_NODE; i++)
            if (treeNodes[i].generated)
            {
                rootNode = &treeNodes[i];
                break;
            }
    }
    return !dfs(rootNode);
}

bool dfs(TreeNode *visitNode)
{
    if (!visitNode->visited)
        visitNode->visited = true;
    else
        return false;

    for (int i = 0; i < visitNode->childNum; i++)
    {
        if (!dfs(visitNode->children[i]))
            return false;
    }

    return true;
}