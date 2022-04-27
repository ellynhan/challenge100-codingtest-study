#include <iostream>
using namespace std;

#define TABLE_COLUMN 3
#define MAX_ROW 100000

#define DP_NUM 2
#define MAX_KEY 0
#define MIN_KEY 1

#define LEFT 0
#define CENTER 1
#define RIGHT 2

int N;
int table[MAX_ROW][TABLE_COLUMN];
int DP[DP_NUM][TABLE_COLUMN];

void writeTable(void);
void initDP(void);

void getDownTable(void);
void copyDP(int (*)[TABLE_COLUMN]);

void printAnswer(void);
int getMaxValue(void);
int getMinValue(void);

int getLargerTwo(int, int);
int getLargerThree(int, int, int);
int getLessTwo(int, int);
int getLessThree(int, int, int);

int main(void)
{
    writeTable();
    initDP();
    getDownTable();
    printAnswer();
}

void writeTable(void)
{
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < TABLE_COLUMN; j++)
            cin >> table[i][j];
}

void initDP(void)
{
    for (int i = 0; i < TABLE_COLUMN; i++)
    {
        DP[MAX_KEY][i] = DP[MIN_KEY][i] = table[0][i];
    }
}

void getDownTable(void)
{

    int prevDP[DP_NUM][TABLE_COLUMN];

    for (int i = 1; i < N; i++)
    {
        copyDP(prevDP);

        DP[MAX_KEY][LEFT] = getLargerTwo(prevDP[MAX_KEY][LEFT], prevDP[MAX_KEY][CENTER]) + table[i][LEFT];
        DP[MAX_KEY][CENTER] = getLargerThree(prevDP[MAX_KEY][RIGHT], prevDP[MAX_KEY][LEFT], prevDP[MAX_KEY][CENTER]) + table[i][CENTER];
        DP[MAX_KEY][RIGHT] = getLargerTwo(prevDP[MAX_KEY][CENTER], prevDP[MAX_KEY][RIGHT]) + table[i][RIGHT];

        DP[MIN_KEY][LEFT] = getLessTwo(prevDP[MIN_KEY][LEFT], prevDP[MIN_KEY][CENTER]) + table[i][LEFT];
        DP[MIN_KEY][CENTER] = getLessThree(prevDP[MIN_KEY][RIGHT], prevDP[MIN_KEY][LEFT], prevDP[MIN_KEY][CENTER]) + table[i][CENTER];
        DP[MIN_KEY][RIGHT] = getLessTwo(prevDP[MIN_KEY][CENTER], prevDP[MIN_KEY][RIGHT]) + table[i][RIGHT];
    }
}

void copyDP(int (*DPCopy)[TABLE_COLUMN])
{
    for (int i = 0; i < DP_NUM; i++)
        for (int j = 0; j < TABLE_COLUMN; j++)
            DPCopy[i][j] = DP[i][j];
}

void printAnswer(void)
{
    cout << getMaxValue() << " " << getMinValue() << endl;
}

int getMaxValue(void)
{
    int *lastRow = DP[MAX_KEY];
    return getLargerThree(lastRow[RIGHT], lastRow[LEFT], lastRow[CENTER]);
}
int getMinValue(void)
{
    int *lastRow = DP[MIN_KEY];
    return getLessThree(lastRow[RIGHT], lastRow[LEFT], lastRow[CENTER]);
}

int getLargerTwo(int a, int b)
{
    return (a > b) ? a : b;
}

int getLargerThree(int a, int b, int c)
{
    return getLargerTwo(c, getLargerTwo(a, b));
}

int getLessTwo(int a, int b)
{
    return (a < b) ? a : b;
}

int getLessThree(int a, int b, int c)
{
    return getLessTwo(c, getLessTwo(a, b));
}