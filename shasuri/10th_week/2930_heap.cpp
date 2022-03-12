

#include <iostream>
#define MAX_SIZE 100000

using namespace std;

void heapInit(void);
int heapPush(int);
int heapPop(void);

void input(void);
void print(int);
void command(void);

int heap[MAX_SIZE];
int heapSize;

int cmdNum;


int main(int argc, char **argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        input();
        print(test_case);
        command();
    }
    return 0;
}

void input(void)
{
    cin >> cmdNum;
}

void print(int testCase)
{
    cout << "#" << testCase << " ";
}

void command(void)
{
    int cmd, pushValue;

    heapInit();

    for (int i = 0; i < cmdNum; i++)
    {
        cin >> cmd;
        switch (cmd)
        {
        case 1:
            cin >> pushValue;
            heapPush(pushValue);
            break;

        case 2:
            cout << heapPop() << " ";
            break;
        default:
            break;
        }
    }

    cout << endl;
}

void heapInit(void)
{
    heapSize = 0;
}

int heapPush(int value)
{
    if (heapSize >= MAX_SIZE)
    {
        return 0; // heap full
    }

    heap[heapSize] = value;
    int current = heapSize;

    int tmp;
    int parent = (current - 1) / 2;
    while (current > 0 && value > heap[parent])
    {
        tmp = heap[parent];
        heap[parent] = value;
        heap[current] = tmp;

        current = parent;
        parent = (current - 1) / 2;
    }

    heapSize += 1;
    return 1; // push sucess
}

int heapPop(void)
{
    if (heapSize <= 0)
        return -1; // heap empty

    int value = heap[0];
    heapSize -= 1;
    heap[0] = heap[heapSize]; // last node to root

    int current = 0; // root index
    int leftChild = current * 2 + 1;
    int rightChild = current * 2 + 2;

    int bigChild; // 좌,우 자식 중 큰 값을 저장하는 변수
    int tmp;
    while (leftChild < heapSize)
    {

        if (rightChild == heapSize)
            bigChild = leftChild;
        else
            bigChild = heap[leftChild] > heap[rightChild] ? leftChild : rightChild;

        if (heap[current] > heap[bigChild])
            break; // 자식과 바꿀필요가 없을때

        tmp = heap[current];
        heap[current] = heap[bigChild];
        heap[bigChild] = tmp;

        current = bigChild;
        leftChild = current * 2 + 1;
        rightChild = current * 2 + 2;
    }

    return value;
}
