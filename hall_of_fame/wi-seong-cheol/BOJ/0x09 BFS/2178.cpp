//
//  2178.cpp
//  main
//
//  Created by wi_seong on 2022/11/11.
//

/*
 [Input]
 4 6
 101111
 101010
 101011
 111011
 [Output]
 15
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 25m
// Url: https://www.acmicpc.net/problem/2178

#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int n, m;
string board[101];
int dist[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[x][y] = 0;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = dx[dir] + cur.X;
            int ny = dy[dir] + cur.Y;
            if(OOB(nx, ny) || dist[nx][ny] >= 0) continue;
            if(board[nx][ny] == '0') continue;
            Q.push({nx, ny});
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        fill(dist[i], dist[i] + m, -1);
    }
    bfs(0, 0);
    cout << dist[n - 1][m - 1] + 1;
    
    return 0;
}
