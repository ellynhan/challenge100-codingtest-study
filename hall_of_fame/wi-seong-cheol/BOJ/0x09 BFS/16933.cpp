//
//  16933.cpp
//  main
//
//  Created by wi_seong on 2023/01/12.
//

/*
 [Input]
 1 4 1
 0010
 [Output]
 5
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000,000
// 난이도: Gold 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/16933

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, m, k;
string board[1001];
int dist[1001][1001][11][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs() {
    queue<tuple<int, int, int, int>> Q;
    Q.push({0, 0, 0, 0});
    dist[0][0][0][0] = 1;
    while(!Q.empty()) {
        auto [x, y, z, t] = Q.front(); Q.pop();
        if(x == n - 1 && y == m - 1)
            return dist[x][y][z][t];
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            int nz = z;
            int nt = 1 - t;
            if(board[nx][ny] == '1') nz++;
            if(dist[nx][ny][nz][nt] > 0 || nz > k) continue;
            if(nz != z && t != 0) {
                if(dist[x][y][z][nt] > 0) continue;
                dist[x][y][z][nt] = dist[x][y][z][t] + 1;
                Q.push({x, y, z, nt});
            } else {
                dist[nx][ny][nz][nt] = dist[x][y][z][t] + 1;
                Q.push({nx, ny, nz, nt});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    cout << bfs();
    
    return 0;
}
