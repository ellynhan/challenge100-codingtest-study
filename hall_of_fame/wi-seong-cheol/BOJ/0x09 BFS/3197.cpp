//
//  3197.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 4 11
 ..XXX...X..
 .X.XXX...L.
 ....XXX..X.
 X.L..XXX...
 [Output]
 2
 */
// 시간복잡도: O(n*m)
// 최악시간: 2,250,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/3197

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
#define X first
#define Y second
const int MX = 1501;
int n, m, x, y;
char board[MX][MX];
bool visited[MX][MX];
bool vis[MX][MX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> Q;
queue<pair<int, int>> Q2;
queue<pair<int, int>> L;
queue<pair<int, int>> L2;

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void melting() {
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        visited[cur.X][cur.Y] = true;
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || visited[nx][ny]) continue;
            if(board[nx][ny] == 'X') Q2.push({nx, ny});
            visited[nx][ny] = true;
        }
    }
}

bool move() {
    while(!L.empty()) {
        auto cur = L.front(); L.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 'X') {
                vis[nx][ny] = 1;
                L2.push({nx, ny});
                continue;
            }
            if(board[nx][ny] == 'L') return true;
            vis[nx][ny] = true;
            L.push({nx, ny});
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'L') {
                x = i;
                y = j;
            }
            if(board[i][j] != 'X')
                Q.push({i, j});
        }
    L.push({x, y});
    board[x][y] = '.';
    vis[x][y] = true;
    
    for(int t = 1; ; t++) {
        melting();
        while(!Q2.empty()) {
            auto cur = Q2.front(); Q2.pop();
            board[cur.X][cur.Y] = '.';
            Q.push({cur.X, cur.Y});
        }
        if(move()) {
            cout << t;
            break;
        }
        while(!L2.empty()) {
            auto cur = L2.front(); L2.pop();
            L.push({cur.X, cur.Y});
        }
    }
    
    return 0;
}
