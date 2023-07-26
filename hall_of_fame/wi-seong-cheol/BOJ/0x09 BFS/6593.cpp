//
//  6593.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 3 4 5
 S....
 .###.
 .##..
 ###.#

 #####
 #####
 ##.##
 ##...

 #####
 #####
 #.###
 ####E

 1 3 3
 S##
 #E#
 ###

 0 0 0
 [Output]
 Escaped in 11 minute(s).
 Trapped!
 */
// 시간복잡도: O(n * m * h)
// 최악시간: 27,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/6593

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
const int SIZE = 31;
int n, m, h;
int sx, sy, sz;
int ex, ey, ez;
string board[SIZE][SIZE];
int dist[SIZE][SIZE][SIZE];
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {1, 0, -1, 0, 0, 0};

bool OOB(int x, int y, int z) { return x < 0 || x >= h || y < 0 || y >= n || z < 0 || z >= m; }

void bfs() {
    queue<tuple<int, int, int>> Q;
    dist[sx][sy][sz] = 0;
    Q.push({sx, sy, sz});
    while(!Q.empty()) {
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        if(x == ex && y == ey && z == ez) {
            cout << "Escaped in " << dist[x][y][z] << " minute(s)." << '\n';
            return;
        }
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(OOB(nx, ny, nz) || dist[nx][ny][nz] != -1) continue;
            if(board[nx][ny][nz] == '#') continue;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            Q.push({nx, ny, nz});
        }
    }
    cout << "Trapped!" << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> h >> n >> m;
        if(h == 0 && n == 0 && m == 0) break;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < n; j++) {
                cin >> board[i][j];
                for(int k = 0; k < m; k++) {
                    dist[i][j][k] = -1;
                    if(board[i][j][k] == 'S') {
                        sx = i;
                        sy = j;
                        sz = k;
                    } else if(board[i][j][k] == 'E') {
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }
        bfs();
    }
    
    return 0;
}
