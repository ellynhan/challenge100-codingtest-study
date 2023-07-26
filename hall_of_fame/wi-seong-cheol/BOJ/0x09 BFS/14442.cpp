//
//  14442.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 6 4 1
 0100
 1110
 1000
 0000
 0111
 0000
 [Output]
 15
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 45m
// Url: https://www.acmicpc.net/problem/14442

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
int n, m, k;
string board[1001];
int dist[1001][1001][11];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 1;
    while(!Q.empty()) {
        auto [x, y, z] = Q.front(); Q.pop();
        if(x == n - 1 && y == m - 1) {
            cout << dist[x][y][z];
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            if(OOB(nx, ny)) continue;
            if(board[nx][ny] == '1') nz++;
            if(dist[nx][ny][nz] > 0 || nz > k) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    bfs();
    
    return 0;
}
