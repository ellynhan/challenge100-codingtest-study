//
//  파괴되지 않은 건물.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 3/22/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Level 3
// Timer: 20m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/92344

#include <iostream>
#include <vector>

using namespace std;
int n, m;
int psum[1001][1001];

int solve(vector<vector<int>>& board, const vector<vector<int>>& skills) {
    int cnt = 0;
    for(auto skill: skills) {
        int type = skill[0];
        int ax = skill[1];
        int ay = skill[2];
        int bx = skill[3];
        int by = skill[4];
        int degree = skill[5];
        int val = type == 1 ? -degree : degree;

        psum[ax][ay] += val;
        psum[bx + 1][ay] -= val;
        psum[ax][by + 1] -= val;
        psum[bx + 1][by + 1] += val;
    }

    for(int i = 0; i < n; i++)
        for(int j = 1; j < m; j++)
            psum[i][j] += psum[i][j - 1];

    for(int i = 1; i < n; i++)
        for(int j = 0; j < m; j++)
            psum[i][j] += psum[i - 1][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] + psum[i][j] > 0) cnt++;

    return cnt;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    n = int(board.size());
    m = int(board[0].size());
    int answer = solve(board, skill);

    return answer;
}
