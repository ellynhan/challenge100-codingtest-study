// [SEA]기초 Double Linked List 연습 / ??? / 1시간
#define MAX_NODE 10000

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node node[MAX_NODE];
int nodeCnt;
Node *head;

Node *getNode(int data)
{
    node[nodeCnt].data = data;
    node[nodeCnt].prev = nullptr;
    node[nodeCnt].next = nullptr;
    return &node[nodeCnt++];
}

void init()
{
    nodeCnt = 0;
    head = getNode(-1);
}

void addNode2Head(int data)
{
    Node *nodeAdd = getNode(data);

    nodeAdd->prev = head;
    nodeAdd->next = head->next;
    head->next = nodeAdd;
    if (nodeAdd->next != nullptr)
        nodeAdd->next->prev = nodeAdd;
}

void addNode2Tail(int data)
{
    Node *ptr = head;
    Node *nodeAdd = getNode(data);

    while (ptr->next != nullptr)
        ptr = ptr->next;

    nodeAdd->prev = ptr;
    ptr->next = nodeAdd;
}

void addNode2Num(int data, int num)
{
    Node *ptr = head;
    Node *nodeAdd = getNode(data);

    int i = 1;
    while (i < num)
    {
        ptr = ptr->next;
        i++;
    }

    nodeAdd->prev = ptr;
    if (ptr->next != nullptr)
    {
        nodeAdd->next = ptr->next;
        ptr->next->prev = nodeAdd;
    }
    ptr->next = nodeAdd;
}

int findNode(int data)
{
    Node *ptr = head;
    int i = 1;

    while (ptr->next != nullptr && ptr->next->data != data)
    {
        ptr = ptr->next;
        i++;
    }

    return i;
}

void removeNode(int data)
{
    Node *ptr = head;

    while (ptr->next != nullptr && ptr->next->data != data)
        ptr = ptr->next;

    if (ptr->next != nullptr)
    {
        if (ptr->next->next != nullptr)
            ptr->next->next->prev = ptr;
        ptr->next = ptr->next->next;
    }
}

int getList(int output[MAX_NODE])
{
    Node *ptr = head;
    int i = 0;
    while (ptr->next != nullptr)
    {
        output[i++] = ptr->next->data;
        ptr = ptr->next;
    }

    return i;
}

int getReversedList(int output[MAX_NODE])
{
    Node *ptr = head;
    int i = 0;
    while (ptr->next != nullptr)
    {
        ptr = ptr->next;
    }

    output[i++] = ptr->data;

    while (ptr->prev->prev != nullptr)
    {
        output[i++] = ptr->prev->data;
        ptr = ptr->prev;
    }

    return i;
}