#include <iostream>

using namespace std;

#define MAX_MAP 500
#define MAX_VAL 1000

int N, M;
int paper[MAX_MAP][MAX_MAP];
int maxValue = 0;

void input(void);
void searchPaper(void);
int searchExceptT(int, int, int, char);
int searchOnlyT(int, int);
int getMaxFour(int, int, int, int);
int getMaxTwo(int, int);
int getMinFour(int, int, int, int);
int getMinTwo(int, int);
int getCheckSquareValue(int, int);
int getSquareValue(int, int);
void printAnswer(void);

int main(void)
{
    input();
    searchPaper();
    printAnswer();
}

void input(void)
{
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> paper[i][j];
}

void searchPaper(void)
{
    int tetroMaxValue;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            tetroMaxValue = getMaxTwo(
                searchExceptT(i, j, 1, 'I'), searchOnlyT(i, j));

            if (maxValue < tetroMaxValue)
                maxValue = tetroMaxValue;
        }
}

int searchExceptT(int n, int m, int depth, char srcDir)
{
    if (n < 0 || n > MAX_MAP - 1 || m < 0 || m > MAX_MAP - 1)
        return 0;

    if (depth == 4)
        return getSquareValue(n, m);

    int upMaxValue = 0;
    int downMaxValue = 0;
    int leftMaxValue = 0;
    int rightMaxValue = 0;

    int maxFourValue = 0;

    // up
    if (srcDir != 'U')
        upMaxValue = searchExceptT(n - 1, m, depth + 1, 'D');

    // down
    if (srcDir != 'D')
        downMaxValue = searchExceptT(n + 1, m, depth + 1, 'U');

    // left
    if (srcDir != 'L')
        leftMaxValue = searchExceptT(n, m - 1, depth + 1, 'R');

    // right
    if (srcDir != 'R')
        rightMaxValue = searchExceptT(n, m + 1, depth + 1, 'L');

    maxFourValue = getMaxFour(upMaxValue, downMaxValue, leftMaxValue, rightMaxValue);

    return getSquareValue(n, m) + maxFourValue;
}

int searchOnlyT(int n, int m)
{

    int blankCount = 0;

    int upMaxValue = 0;
    int downMaxValue = 0;
    int leftMaxValue = 0;
    int rightMaxValue = 0;

    int minFourValue = 0;
    int sumFourValue = 0;

    // up
    upMaxValue = getCheckSquareValue(n - 1, m);
    if (upMaxValue == 0)
        blankCount++;
    // down
    downMaxValue = getCheckSquareValue(n + 1, m);
    if (downMaxValue == 0)
        blankCount++;
    // left
    leftMaxValue = getCheckSquareValue(n, m - 1);
    if (leftMaxValue == 0)
        blankCount++;
    // right
    rightMaxValue = getCheckSquareValue(n, m + 1);
    if (rightMaxValue == 0)
        blankCount++;

    if (blankCount > 1)
        return 0;

    minFourValue = getMinFour(upMaxValue, downMaxValue, leftMaxValue, rightMaxValue);
    sumFourValue = upMaxValue + downMaxValue + leftMaxValue + rightMaxValue;

    return getSquareValue(n, m) + sumFourValue - minFourValue;
}

int getMaxFour(int u, int d, int l, int r)
{
    return getMaxTwo(u, getMaxTwo(d, getMaxTwo(l, r)));
}

int getMaxTwo(int a, int b)
{
    return (a > b) ? a : b;
}

int getMinFour(int u, int d, int l, int r)
{
    return getMinTwo(u, getMinTwo(d, getMinTwo(l, r)));
}

int getMinTwo(int a, int b)
{
    return (a < b) ? a : b;
}

int getCheckSquareValue(int n, int m)
{
    if (n < 0 || n > MAX_MAP - 1 || m < 0 || m > MAX_MAP - 1)
        return 0;
    else
        return getSquareValue(n, m);
}

int getSquareValue(int n, int m)
{
    return paper[n][m];
}

void printAnswer(void)
{
    cout << maxValue << endl;
}