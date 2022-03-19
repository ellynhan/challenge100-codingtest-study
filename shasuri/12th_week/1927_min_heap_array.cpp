#include <stdio.h>
#define MAX_NODE 100000
#define HEAP_EMPTY_CODE 0
#define TOP_INDEX 0

using namespace std;

int heapSize = 0;
int heapArray[MAX_NODE];

void command(int);

void heapPush(int);
void swapPtr(int *, int *);
void popPrint(void);
int heapPop(void);
int getHeapEmptyCode(void);
int getRootValue(void);
int getHeapMinValue(void);
int getSmallerChild(int, int);

int main(void)
{
    //     ios_base::sync_with_stdio(false);
    //     cin.tie(NULL);
    //     cout.tie(NULL);

    int N, cmd;
    scanf("%d", &N);
    // cin >> N;

    for (int i = 0; i < N; i++)
    {
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
    // heapfull
    if (heapSize > MAX_NODE)
        return;

    heapArray[heapSize] = newNum;
    int newIndex = heapSize;
    int parentIndex = (newIndex - 1) / 2;

    while ((newIndex != TOP_INDEX) && (heapArray[newIndex] < heapArray[parentIndex]))
    {
        // swap only value
        swapPtr(&heapArray[newIndex], &heapArray[parentIndex]);

        // refresh nodes
        newIndex = parentIndex;
        parentIndex = (newIndex - 1) / 2;
    }

    heapSize++;
}

void swapPtr(int *t, int *u)
{
    int temp;

    temp = *t;
    *t = *u;
    *u = temp;
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

    if (heapSize <= 0)
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
    return heapArray[TOP_INDEX];
}

int getHeapMinValue(void)
{
    int minValue = heapArray[TOP_INDEX];

    int lastIndex = heapSize - 1;
    heapArray[TOP_INDEX] = heapArray[lastIndex];
    heapSize--;

    int currentIndex = TOP_INDEX;

    int leftChild = currentIndex * 2 + 1;
    int rightChild = currentIndex * 2 + 2;

    while (leftChild < heapSize)
    {
        int smallChild;

        if (rightChild >= heapSize)
            smallChild = leftChild;
        else
            smallChild = getSmallerChild(leftChild, rightChild);

        if (heapArray[currentIndex] < heapArray[smallChild])
            break;

        // swap only value
        swapPtr(&heapArray[currentIndex], &heapArray[smallChild]);

        // refresh nodes
        currentIndex = smallChild;
        leftChild = currentIndex * 2 + 1;
        rightChild = currentIndex * 2 + 2;
    }

    return minValue;
}

int getSmallerChild(int l, int r)
{
    if (heapArray[l] <= heapArray[r])
        return l;
    else
        return r;
}
