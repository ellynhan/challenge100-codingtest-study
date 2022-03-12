#include <iostream>
#define TESTCASE_NUM 10
#define ELEMENT_PRINT 10

using namespace std;

struct Node
{
    int cipher;
    Node *next;
    Node *prev;
} node[5000];

int nodeCount;

Node *head = &node[0];
Node *tail = &node[1];

void input(void);
void command(void);
void print(int);

void insertNode(void);
void deleteNode(void);
void addNode(void);

Node *getNodeByIndex(int);
Node *appendNode(int, Node *);

int main(int argc, char **argv)
{
    int test_case;
    int T;
    // freopen("input.txt", "r", stdin);
    T = TESTCASE_NUM;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        input();
        command();
        print(test_case);
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}

void input(void)
{
    nodeCount = 2;
    head->next = tail;
    head->prev = nullptr;

    tail->prev = head;
    tail->next = nullptr;

    int N;
    cin >> N;

    int cipher;
    Node *ptr = head;
    for (int i = 0; i < N; i++)
    {
        cin >> cipher;
        ptr = appendNode(cipher, ptr);
    }
}

Node *getNodeByIndex(int index)
{
    Node *ptr = head;
    for (int i = 0; i < index; i++)
        ptr = ptr->next;

    return ptr;
}

Node *appendNode(int cipher, Node *prevNode)
{

    Node *newNode = &node[nodeCount++];

    newNode->cipher = cipher;

    newNode->prev = prevNode;
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;

    return newNode;
}

void command(void)
{
    int cmdCount;
    char cmd;
    cin >> cmdCount;

    for (int i = 0; i < cmdCount; i++)
    {
        cin >> cmd;

        if (cmd == 'I')
            insertNode();
        if (cmd == 'D')
            deleteNode();
        if (cmd == 'A')
            addNode();
    }
}

void insertNode(void)
{
    int x, y, s;
    cin >> x >> y;
    Node *ptr = getNodeByIndex(x);

    for (int i = 0; i < y; i++)
    {
        cin >> s;
        ptr = appendNode(s, ptr);
    }
}

void deleteNode(void)
{
    int x, y;
    cin >> x >> y;

    Node *startPtr = getNodeByIndex(x);
    Node *endPtr = startPtr;

    for (int i = 0; i < y; i++)
        endPtr = endPtr->next;

    endPtr->next->prev = startPtr;
    startPtr->next = endPtr->next;
}

void addNode(void)
{
    int x, y, s;

    cin >> y;

    Node *ptr = tail->prev;
    for (int i = 0; i < y; i++)
    {
        cin >> s;
        ptr = appendNode(s, ptr);
    }
}

void print(int testCase)
{
    cout << "#" << testCase << " ";
    Node *ptr = head;

    for (int i = 0; i < ELEMENT_PRINT; i++)
    {
        cout << ptr->next->cipher << " ";
        ptr = ptr->next;
    }

    cout << endl;
}