//
//  튜브의 소개팅.cpp
//  main
//
//  Created by wi_seong on 2/13/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 6,250,000
// 난이도: Level 4
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1839

#include <iostream>
#include <vector>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;
typedef long long ll;
int N, M, S;
ll cache[51][51][2501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= N || y < 0 || y >= M; }

ll solve(int x, int y, int dist, const vector<vector<int>>& board) {
    ll& ret = cache[x][y][dist];
    if(x == N - 1 && y == M - 1 && dist == 0) return ret = 0;
    if(ret != -1) return ret;
    ret = INT_MAX;

    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] == -1 || dist < -1) continue;
        ll result = solve(nx, ny, dist - 1, board) + board[x][y];
        if(result <= S)
            ret = min(ret, result);
    }

    return ret;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, int s, vector<vector<int>> time_map) {
    vector<int> answer(2);
    N = m;
    M = n;
    S = s;
    memset(cache, -1, sizeof(cache));

    for(int dist = N + M - 2; dist <= N * M; dist++) {
        ll result = solve(0, 0, dist, time_map);

        if(result < INT_MAX) {
            answer[0] = dist;
            answer[1] = result;
            break;
        }
    }

    return answer;
}
