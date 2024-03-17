//
//  20158.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/3/24.
//

/*
 [Input]
 5
 0 0 0 2 0
 0 1 0 0 0
 0 0 0 3 0
 5 0 0 0 0
 0 0 6 0 0
 [Output]
 6
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Platinum 5
// Timer: 2h
// Url: https://www.acmicpc.net/problem/20158

#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;
#define X first
#define Y second
#define INF 0x7f7f7f7f
#define MAX 101
int n;
int result = INF;
int board[MAX][MAX];
int dist[MAX][MAX][4][MAX];
bool visited[MAX][MAX][4][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void init() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int dir = 0; dir < 4; dir++) {
                for(int k = 0; k < n; k++) {
                    dist[i][j][dir][k] = -1;
                }
            }
        }
    }
    dist[0][0][0][0] = 0;
    dist[0][0][1][0] = 0;
    dist[0][0][2][0] = 0;
    dist[0][0][3][0] = 0;
}

void bfs() {
    queue<tuple<int, int, int, int>> Q;
    Q.push({0, 0, 0, 0});
    Q.push({0, 0, 1, 0});

    while(!Q.empty()) {
        int x, y, z, k;
        tie(x, y, z, k) = Q.front(); Q.pop();
        visited[x][y][z][k] = false;
        if(x == n - 1 && y == n - 1) {
            result = min(result, dist[x][y][z][k]);
            return;
        }
        for(int dir = 0; dir < 4; dir++) {
            int nx = x;
            int ny = y;

            if(z == dir) {
                bool Flag = true; // Flag가 true라면 가속도가 붙은 채 움직일 수 있다.
                for (int j = 1; j <= k + 1; j++) {
                    nx = x + (dx[z] * j);
                    ny = y + (dy[z] * j);
                    if(OOB(nx, ny)
                       || !((board[nx][ny] == 0 || dist[x][y][z][k] <= board[nx][ny]))) {
                        Flag = false;
                        break;
                    }
                }
                if(Flag) {
                    if(visited[nx][ny][z][k + 1]) continue;
                    if(dist[nx][ny][z][k + 1] != -1) continue;
                    if(board[nx][ny] != 0 && dist[x][y][z][k] + 1 >= board[nx][ny]) continue;
                    visited[nx][ny][z][k + 1] = true;
                    dist[nx][ny][z][k + 1] = dist[x][y][z][k] + 1;
                    Q.push({nx, ny, z, k + 1});
                }

            } else {
                nx = x + dx[dir];
                ny = y + dy[dir];
                if(OOB(nx, ny)) continue;
                if(visited[nx][ny][z][k + 1]) continue;
                if(dist[nx][ny][dir][1] != -1) continue;
                if(board[nx][ny] != 0 && dist[x][y][z][k] + 1 >= board[nx][ny]) continue;
                visited[nx][ny][dir][1] = true;
                dist[nx][ny][dir][1] = dist[x][y][z][k] + 1;
                Q.push({nx, ny, dir, 1});
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    init();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    }
    bfs();
    if(result == INF) cout << "Fired";
    else cout << result;

	return 0;
}
