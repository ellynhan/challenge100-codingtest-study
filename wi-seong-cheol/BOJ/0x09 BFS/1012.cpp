//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 2
 10 8 17
 0 0
 1 0
 1 1
 4 2
 4 3
 4 5
 2 4
 3 4
 7 4
 8 4
 9 4
 7 5
 8 5
 9 5
 7 6
 8 6
 9 6
 10 10 1
 5 5
 [Output]
 5
 1
 */
// 시간복잡도: O(n * m)
// 최악시간: 2,500
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1012

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 51;
int n, m, k;
int board[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 0) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        int ans = 0;
        cin >> n >> m >> k;
        queue<pair<int, int>> Q;
        for(int i = 0; i < n; i++) {
            fill(board[i], board[i] + m + 1, 0);
            fill(vis[i], vis[i] + m + 1, false);
        }
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            board[x][y] = 1;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(board[i][j] == 1 && !vis[i][j]) {
                    bfs(i, j);
                    ans++;
                }
        cout << ans << '\n';
    }
    
    return 0;
}
