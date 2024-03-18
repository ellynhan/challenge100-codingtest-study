//
//  17825.cpp
//  main
//
//  Created by wi_seong on 3/17/24.
//

/*
 [Input]
 5 5 5 5 5 5 5 5 5 5
 [Output]
 130
 */
// 시간복잡도: O(10 * 2 ^ 20)
// 최악시간: 10,485,760
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17825

#include <iostream>

using namespace std;
const int board[33][6] = {
    {0,1,2,3,4,5},
    {2,2,3,4,5,6},
    {4,3,4,5,6,7},
    {6,4,5,6,7,8},
    {8,5,6,7,8,9},
    {10,21,22,23,24,25},
    {12,7,8,9,10,11},
    {14,8,9,10,11,12},
    {16,9,10,11,12,13},
    {18,10,11,12,13,14},
    {20,27,28,24,25,26},
    {22,12,13,14,15,16},
    {24,13,14,15,16,17},
    {26,14,15,16,17,18},
    {28,15,16,17,18,19},
    {30,29,30,31,24,25},
    {32,17,18,19,20,32},
    {34,18,19,20,32,32},
    {36,19,20,32,32,32},
    {38,20,32,32,32,32},
    {40,32,32,32,32,32},
    {13,22,23,24,25,26},
    {16,23,24,25,26,20},
    {19,24,25,26,20,32},
    {25,25,26,20,32,32},
    {30,26,20,32,32,32},
    {35,20,32,32,32,32},
    {22,28,24,25,26,20},
    {24,24,25,26,20,32},
    {28,30,31,24,25,26},
    {27,31,24,25,26,20},
    {26,24,25,26,20,32},
    {0,32,32,32,32,32}
};
int ans;
int dice[10];

int fetchScore(int state) {
    int ret = 0;
    bool vis[33] = {0, };
    int pos[4] = {0, };

    for(int turn = 0; turn < 10; turn++) {
        int cur = (state >> (turn * 2)) & 3;
        int move = dice[turn];
        int& curPos = pos[cur];
        int nextPos = board[curPos][move];
        int addScore = board[nextPos][0];

        if(vis[nextPos] && nextPos != 32) return -1;

        vis[curPos] = 0;
        vis[nextPos] = 1;
        curPos = nextPos;
        ret += addScore;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 0; i < 10; i++) cin >> dice[i];
    for(int state = 0; state < (1 << 20); state++) {
        int cand = fetchScore(state);
        if(ans < cand) ans = cand;
    }
    cout << ans;

    return 0;
}
