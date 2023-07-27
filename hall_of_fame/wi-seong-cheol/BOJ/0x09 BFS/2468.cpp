//
//  2468.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 5
 6 8 2 6 2
 3 2 3 4 6
 6 7 3 3 2
 7 2 5 3 6
 8 9 5 2 7
 [Output]
 6
 */
// 시간복잡도: O(n * n)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 11m
// Url: https://www.acmicpc.net/problem/2468

#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 101;
int n;
int board[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs(int x, int y, int h) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] <= h) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    int max_height = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            max_height = max(max_height, board[i][j]);
        }
    }
    int ans = 1;
    for(int h = 1; h <= max_height; h++) {
        int cnt = 0;
        for(int i = 0; i < n; i++)
            fill(vis[i], vis[i] + n + 1, false);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] > h && !vis[i][j]) {
                    cnt++;
                    bfs(i, j, h);
                }
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    
    return 0;
}
