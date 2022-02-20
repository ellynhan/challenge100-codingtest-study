// [SEA] 12317. 기초 DFS 연습 / ??? / 1시간
#define MAX_NSIZE 40
#define UNIQUE_ABILITY 100

using namespace std;

int dynasty[UNIQUE_ABILITY][MAX_NSIZE];
int childNum[UNIQUE_ABILITY];

class ChildStack
{
private:
    int container[MAX_NSIZE];
    int top = -1;

public:
    ChildStack(void);
    ~ChildStack(void);
    void push(int);
    int pop(void);
};

ChildStack::ChildStack() {}
ChildStack::~ChildStack()
{
    this->top = -1;
}

void ChildStack::push(int value)
{
    if (top >= MAX_NSIZE)
        return;
    container[++(this->top)] = value;
}

int ChildStack::pop(void)
{
    if (top <= -1)
        return -1;
    return container[(this->top)--];
}

void dfs_init(int N, int path[100][2])
{
    int i;
    for (i = 0; i < UNIQUE_ABILITY; i++)
        childNum[i] = 0;

    for (i = 0; i < N - 1; i++)
    {
        // cout << path[i][0] << " : " << path[i][1] << endl;
        dynasty[path[i][0]][childNum[path[i][0]]] = path[i][1];
        childNum[path[i][0]]++;
    }
}

int dfs(int n)
{
    ChildStack childStack;
    int head = n;
    while (true)
    {
        for (int i = childNum[head] - 1; i > -1; i--)
        {
            // cout << "head : " << head << " i : " << i << endl;
            childStack.push(dynasty[head][i]);
        }

        head = childStack.pop();
        if (head > n || head == -1)
            break;
    }
    // cout << head << endl;
    return head;
}
