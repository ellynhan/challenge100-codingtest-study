//
//  7569.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5 3 1
 0 -1 0 0 0
 -1 -1 0 1 1
 0 0 0 1 1
 [Output]
 -1
 */
// 시간복잡도: O(n * m * h)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/7569

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
#define X first
#define Y second
const int SIZE = 101;
int n, m, h;
int board[SIZE][SIZE][SIZE];
int dist[SIZE][SIZE][SIZE];
int dx[] = {0, 0, 0, 0, 1, -1};
int dy[] = {0, 1, 0, -1, 0, 0};
int dz[] = {1, 0, -1, 0, 0, 0};
int cnt1, cnt2;
queue<tuple<int, int, int>> Q;

bool OOB(int a, int b, int c) { return a < 0 || a >= h || b < 0 || b >= n || c < 0 || c >= m; }

int bfs() {
    while(!Q.empty()) {
        int x, y, z;
        tie(x, y, z) = Q.front(); Q.pop();
        for(int dir = 0; dir < 6; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            int nz = z + dz[dir];
            if(OOB(nx, ny, nz) || dist[nx][ny][nz] != -1 || board[nx][ny][nz] == -1) continue;
            cnt2++;
            dist[nx][ny][nz] = dist[x][y][z] + 1;
            if(cnt1 == cnt2) {
                return dist[nx][ny][nz];
            }
            Q.push({nx, ny, nz});
        }
    }
    return -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> m >> n >> h;
    cnt1 = m * n * h;
    cnt2 = 0;
    
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < m; k++) {
                cin >> board[i][j][k];
                dist[i][j][k] = -1;
                if(board[i][j][k] == 1) {
                    cnt2++;
                    Q.push({i, j, k});
                    dist[i][j][k] = 0;
                } else if(board[i][j][k] == -1) {
                    cnt1--;
                }
            }
        }
    }
    int res = 0;
    if(cnt1 == cnt2) {
        cout << res;
        return 0;
    }
    cout << bfs();
    
    return 0;
}
