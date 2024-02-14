//
//  가장 큰 정사각형 찾기.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/12905

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
int d[1001][1001];

int solve(const vector<vector<int>>& board) {
    int ret = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i - 1][j - 1] == 1) {
                d[i][j] = min(d[i - 1][j - 1], min(d[i][j - 1], d[i - 1][j])) + 1;
                ret = max(ret, d[i][j]);
            }
        }
    }

    return ret * ret;
}

int solution(vector<vector<int>> board) {
    n = int(board.size());
    m = int(board[0].size());
    int answer = solve(board);

    return answer;
}
