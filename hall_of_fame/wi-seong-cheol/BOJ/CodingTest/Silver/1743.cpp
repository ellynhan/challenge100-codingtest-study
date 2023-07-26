//
//  1743.cpp
//  main
//
//  Created by wi_seong on 2023/04/04.
//

/*
 [Input]
 3 4 5
 3 2
 2 2
 3 1
 2 3
 1 1
 [Output]
 4
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1743

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, k;
int board[101][101];
bool vis[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > m; }

int bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    int cnt = 1;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] != 1) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    while(k--) {
        int x, y; cin >> x >> y;
        board[x][y] = 1;
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(board[i][j] && !vis[i][j])
                ans = max(ans, bfs(i, j));
    cout << ans;
    
    return 0;
}
