//
//  1926.cpp
//  main
//
//  Created by wi_seong on 2022/11/11.
//

/*
 [Input]
 6 5
 1 1 0 1 1
 0 1 1 0 0
 0 0 0 0 0
 1 0 1 1 1
 0 0 1 1 1
 0 0 1 1 1
 [Output]
 4
 9
 */
// 시간복잡도: O(nm)
// 최악시간: 250,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1926

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m;
int cnt, maxSize;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int board[501][501];
bool vis[501][501];

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    int s = 0;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        s++;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
    maxSize = max(maxSize, s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(board[i][j] == 1 && !vis[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << '\n';
    cout << maxSize << '\n';
    
    return 0;
}
