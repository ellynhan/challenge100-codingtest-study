#include <iostream>

using namespace std;

struct Node
{
    int num;
    Node *next;
    Node *prev;
};

int N, M, L, arraySize;
Node *head = new Node({-2, nullptr, nullptr});
Node *tail = new Node({-1, nullptr, nullptr});

Node *moveIndex(int index)
{
    Node *ptr = head;

    for (int i = 0; i < index; i++)
        ptr = ptr->next;

    return ptr;
}

void insertNode(int index, int numInsert)
{
    Node *ptr = moveIndex(index);

    Node *nodeInsert = new Node({numInsert, ptr->next, ptr});

    ptr->next->prev = nodeInsert;
    ptr->next = nodeInsert;

    arraySize++;
}

void deleteNode(int index)
{
    Node *ptr = moveIndex(index);

    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;

    arraySize--;
}

void changeNode(int index, int numChange)
{
    Node *ptr = moveIndex(index);

    ptr->next->num = numChange;
}

void init(void)
{
    head->next = tail;
    tail->prev = head;
}

void input(void)
{
    cin >> N >> M >> L;
    arraySize = N;

    int nodeNum;

    Node *ptr = head;

    for (int i = 0; i < N; i++)
    {
        cin >> nodeNum;
        ptr->next = new Node({nodeNum, ptr->next, ptr});
        ptr = ptr->next;
    }
}

void solve(void)
{
    char cmd;
    int index, num;
    for (int i = 0; i < M; i++)
    {
        cin >> cmd;

        if (cmd == 'I')
        {
            cin >> index >> num;
            insertNode(index, num);
        }
        if (cmd == 'D')
        {
            cin >> index;
            deleteNode(index);
        }
        if (cmd == 'C')
        {
            cin >> index >> num;
            changeNode(index, num);
        }
    }
}

void print(int testCase)
{
    int output;
    if (L > arraySize - 1)
        output = -1;
    else
    {
        Node *ptr = moveIndex(L);
        output = ptr->next->num;
    }
    cout << "#" << testCase << " " << output << endl;
}

int main(void)
{
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        init();
        input();
        solve();
        print(t);
    }
}
