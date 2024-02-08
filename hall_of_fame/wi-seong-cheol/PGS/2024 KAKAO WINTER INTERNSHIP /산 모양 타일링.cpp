//
//  산 모양 타일링.cpp
//  main
//
//  Created by wi_seong on 1/24/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/258705#

#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
const int MOD = 10007;
vector<int> board;
int N;
int cache[2][100001];

int solve(bool usedBottom, int idx) {
    int &ret = cache[usedBottom][idx];
    if(idx == N - 1) return ret = !usedBottom + board[idx] + 2;
    if(ret != -1) return ret;
    ret = 0;

    if(usedBottom) {
        ret = (ret + (solve(false, idx + 1) * (board[idx] + 1))) % MOD;
        ret = (ret + (solve(true, idx + 1))) % MOD;
    } else {
        ret = (ret + (solve(false, idx + 1) * (board[idx] + 2))) % MOD;
        ret = (ret + (solve(true, idx + 1))) % MOD;
    }

    return ret;
}

int solution(int n, vector<int> tops) {
    N = n;
    board = tops;
    memset(cache, -1, sizeof(cache));
    int answer = solve(false, 0);

    return answer;
}
