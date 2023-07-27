//
//  7576.cpp
//  main
//
//  Created by wi_seong on 2022/11/11.
//

/*
 [Input]
 6 4
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 0
 0 0 0 0 0 1
 [Output]
 8
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/7576

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans, n, m;
int board[1001][1001];
int date[1001][1001];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
queue<pair<int, int>> Q;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs() {
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny)) continue;
            if(date[nx][ny] >= 0) continue;
            date[nx][ny] = date[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 1) Q.push({i,j});
            if(board[i][j] == 0) date[i][j] = -1;
        }
    }
    bfs();
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(date[i][j] == -1) {
                cout << -1;
                return 0;
            }
            ans = max(ans, date[i][j]);
        }
    }
    cout << ans;
    
    return 0;
}
