//
//  2206.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 6 4
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
// Timer: 34m
// Url: https://www.acmicpc.net/problem/2206

#include <iostream>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
#define X first
#define Y second
const int SIZE = 1001;
int n, m;
string board[SIZE];
int dist[SIZE][SIZE][2];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = dist[0][0][1] = 1;
    while(!Q.empty()) {
        auto [x, y, z] = Q.front(); Q.pop();
        if(x == n - 1 && y == m - 1) {
            cout << dist[x][y][z];
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx, ny)) continue;
            int nz = z;
            if(board[nx][ny] == '1') nz++;
            if(nz > 1 || dist[nx][ny][nz] != -1) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> board[i];
        for(int j = 0; j < m; j++)
            fill(dist[i][j], dist[i][j] + 2, -1);
    }
    bfs();
    
    return 0;
}
