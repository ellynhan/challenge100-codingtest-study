//
//  2146.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 10
 1 1 1 0 0 0 0 1 1 1
 1 1 1 1 0 0 0 0 1 1
 1 0 1 1 0 0 0 0 1 1
 0 0 1 1 1 0 0 0 0 1
 0 0 0 1 0 0 0 0 0 1
 0 0 0 0 0 0 0 0 0 1
 0 0 0 0 0 0 0 0 0 0
 0 0 0 0 1 1 0 0 0 0
 0 0 0 0 1 1 1 0 0 0
 0 0 0 0 0 0 0 0 0 0
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2146

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
const int MX = 0x7f7f7f7f;
const int SIZE = 101;
int n, m;
int board[SIZE][SIZE];
bool vis[SIZE][SIZE];
int dist[SIZE][SIZE];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs(int x, int y, int mark) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        board[cur.X][cur.Y] = mark;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] != 1) continue;
            vis[nx][ny] = true;
            Q.push({nx, ny});
        }
    }
}

void isLand() {
    int mark = 1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(board[i][j] == 1 && !vis[i][j])
                bfs(i, j, mark++);
}

int solve() {
    int ans = MX;
    queue<pair<int, int>> Q;
    for(int i = 0; i < n; i++) {
        fill(dist[i], dist[i] + n, -1);
        for(int j = 0; j < n; j++) {
            if(board[i][j] != 0) {
                Q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || board[cur.X][cur.Y] == board[nx][ny]) continue;
            if(board[nx][ny] != 0) {
                ans = min(ans, dist[nx][ny] + dist[cur.X][cur.Y]);
            } else {
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
    }
    
    return ans;
}

void input() {
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    isLand();
    cout << solve();
    
    return 0;
}
