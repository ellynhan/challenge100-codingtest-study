#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "solution.cpp"
#include <iostream>
#endif

#include <stdio.h>

#define CMD_INIT 1
#define CMD_BUY 2
#define CMD_SELL 3
#define CMD_CANCEL 4
#define CMD_BEST_PROFIT 5

extern void init();
extern int buy(int mNumber, int mStock, int mQuantity, int mPrice);
extern int sell(int mNumber, int mStock, int mQuantity, int mPrice);
extern void cancel(int mNumber);
extern int bestProfit(int mStock);

/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////

static bool run()
{
    int numQuery;

    int mNumber, mStock, mQuantity, mPrice;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_BUY:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = buy(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
                // printf("%d %d %d %d\n", mNumber, mStock, mQuantity, mPrice);
                // printf("Wrong.. You: %d, answer: %d\n", userAns, ans);
            }
            break;
        case CMD_SELL:
            scanf("%d %d %d %d", &mNumber, &mStock, &mQuantity, &mPrice);
            userAns = sell(mNumber, mStock, mQuantity, mPrice);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
                // printf("%d %d %d %d\n", mNumber, mStock, mQuantity, mPrice);
                // printf("Wrong.. You: %d, answer: %d\n", userAns, ans);
            }
            break;
        case CMD_CANCEL:
            scanf("%d", &mNumber);
            cancel(mNumber);
            break;
        case CMD_BEST_PROFIT:
            scanf("%d", &mStock);
            userAns = bestProfit(mStock);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
                // printf("%d\n", mStock);
                // printf("Wrong.. You: %d, answer: %d\n", userAns, ans);
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdin, NULL);
    setbuf(stdout, NULL);
    freopen("sample_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);
    // printf("%d %d", T, MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
