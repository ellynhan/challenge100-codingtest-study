//
//  11967.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 3 6
 1 1 1 2
 2 1 2 2
 1 1 1 3
 2 3 3 1
 1 3 1 2
 1 3 2 1
 [Output]
 5
 */
// 시간복잡도: O(n*m)
// 최악시간: 10,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/11967

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, m, x, y, a, b, ans;
vector<pair<int, int>> adj[101][101];
bool vis[101][101];
bool light[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x <= 0 || x > n || y <= 0 || y > n; }

bool turnOn(int x, int y) {
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(vis[nx][ny]) return true;
    }
    return false;
}

void bfs() {
    queue<pair<int, int>> Q;
    Q.push({1, 1});
    vis[1][1] = true;
    light[1][1] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(auto nxt : adj[cur.X][cur.Y]) {
            if(vis[nxt.X][nxt.Y]) continue;
            if(turnOn(nxt.X, nxt.Y)) {
                vis[nxt.X][nxt.Y] = 1;
                Q.push({nxt.X, nxt.Y});
            }
            light[nxt.X][nxt.Y] = 1;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny] || !light[nx][ny]) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        adj[x][y].push_back({a, b});
    }
    bfs();
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            ans += light[i][j];
    cout << ans;
    
    return 0;
}
