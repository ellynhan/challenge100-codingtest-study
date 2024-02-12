//
//  고고학 최고의 발견.cpp
//  main
//
//  Created by wi_seong on 2/8/24.
//

// 시간복잡도: O((4 ^ n) * n ^ 2)
// 최악시간: 4,194,304
// 난이도: Level 3
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/131702

#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
const int INF = 1e9 + 7;
int n, answer;
int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void rotate(vector<vector<int>>& clockHands, int x, int y, int val) {
    for(int dir = 0; dir < 5; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        clockHands[nx][ny] = (clockHands[nx][ny] + 4 + val) % 4;
    }
}

bool check(const vector<vector<int>>& clockHands) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            if(clockHands[i][j] != 0) return false;
    }
    return true;
}

int countRotate(vector<vector<int>> clockHands) {
    int ret = 0;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(clockHands[i - 1][j] == 0) continue;
            int dif = 4 - clockHands[i - 1][j];
            rotate(clockHands, i, j, dif);
            ret += dif;
        }
    }
    if(!check(clockHands)) return -1;
    return ret;
}

void solve(int k, int sum, vector<vector<int>>& clockHands) {
    if(k == n) {
        int result = countRotate(clockHands);
        if(result != -1) {
            answer = min(answer, result + sum);
        }
        return;
    }

    for(int x = 0; x < 4; x++) {
        rotate(clockHands, 0, k, x);
        solve(k + 1, sum + x, clockHands);
        rotate(clockHands, 0, k, -x);
    }
}

int solution(vector<vector<int>> clockHands) {
    answer = INF;
    n = int(clockHands.size());

    solve(0, 0, clockHands);

    return answer;
}
