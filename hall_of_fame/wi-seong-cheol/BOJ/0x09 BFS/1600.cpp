//
//  1600.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 1
 4 4
 0 0 0 0
 1 0 0 0
 0 0 1 0
 0 1 0 0
 [Output]
 4
 */
// 시간복잡도: O(n^2)
// 최악시간: 1,200,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1600

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
int k, w, h;
int dist[201][201][31];
int board[201][201];
int dx[] = {0, 1, 0, -1, 1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {1, 0, -1, 0, 2, 1, -1, -2, -2, -1, 1, 2};

bool OOB(int x, int y) { return x < 0 || x > h || y < 0 || y > w; }

void bfs() {
    queue<tuple<int, int, int>> Q;
    Q.push({0, 0, 0});
    dist[0][0][0] = 0;
    
    while(!Q.empty()) {
        auto [x, y, z] = Q.front(); Q.pop();
        if(x == h - 1 && y == w - 1) {
            cout << dist[x][y][z] << '\n';
            return;
        }
        for(int dir = 0; dir < 12; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z;
            if(OOB(nx, ny) || board[nx][ny] == 1) continue;
            if(dir >= 4) nz++;
            if(dist[nx][ny][nz] != -1 || nz > k) continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> k >> w >> h;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            fill(dist[i][j], dist[i][j] + 31, -1);
            cin >> board[i][j];
        }
    }
    bfs();
    
    return 0;
}
