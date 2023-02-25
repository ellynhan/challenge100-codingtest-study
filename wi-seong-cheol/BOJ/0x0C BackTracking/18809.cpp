//
//  18809.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/22.
//

/*
 [Input]
 2 2 1 1
 2 1
 1 2
 [Output]
 2
 */
// 시간복잡도: O((2^n)^2)
// 최악시간: 1,048,576
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/18809

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, g, r;
int board[51][51];
int brute[10];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int, int>> cand;
unsigned long candsz;
const int EMPTY = 0;
const int GREEN = 1;
const int RED = 2;
const int FLOWER = 3;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int solve() {
    int cnt = 0;
    pair<int, int> state[51][51];
    queue<pair<int, int>> Q;
    for(int i = 0; i < candsz; i++) {
        if(brute[i] == GREEN || brute[i] == RED) {
            state[cand[i].X][cand[i].Y] = {0, brute[i]};
            Q.push(cand[i]);
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int curtime = state[cur.X][cur.Y].X;
        int curcolor = state[cur.X][cur.Y].Y;
        if(state[cur.X][cur.Y].Y == FLOWER) continue;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[nx][ny] == 0) continue;
            if(state[nx][ny].Y == EMPTY) {
                state[nx][ny] = {curtime + 1, curcolor};
                Q.push({nx, ny});
            } else if(state[nx][ny].Y == RED) {
                if(curcolor == GREEN && state[nx][ny].X == curtime + 1) {
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            } else if(state[nx][ny].Y == GREEN) {
                if(curcolor == RED && state[nx][ny].X == curtime + 1) {
                    cnt++;
                    state[nx][ny].Y = FLOWER;
                }
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> g >> r;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 2)
                cand.push_back({i, j});
        }
    }
    candsz = cand.size();
    fill(brute + candsz - g - r, brute + candsz - r, GREEN);
    fill(brute + candsz - r, brute + candsz, RED);
    do {
        ans = max(ans, solve());
    } while(next_permutation(brute, brute + candsz));
    cout << ans;
    
    return 0;
}
