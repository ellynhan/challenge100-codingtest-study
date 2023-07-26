//
//  14497.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/11.
//

/*
 [Input]
 3 3
 2 2 1 1
 #00
 0*0
 000
 [Output]
 1
 */
// 시간복잡도: O((n * m) * n)
// 최악시간: 27,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14497

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define X first
#define Y second
int t;
int n, m;
pair<int, int> J, C;
char board[301][301];
bool vis[301][301];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

bool jump() {
    memset(vis, false, sizeof(vis));
    queue<pair<int, int>> Q;
    Q.push(J);
    vis[J.X][J.Y] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == '1') {
                vis[nx][ny] = true;
                board[nx][ny] = '0';
            } else if(board[nx][ny] == '0') {
                vis[nx][ny] = true;
                Q.push({nx, ny});
            } else if(board[nx][ny] == '#') {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    cin >> J.X >> J.Y >> C.X >> C.Y;
    J.X--; J.Y--;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    while(1) {
        t++;
        if(jump()) {
            cout << t;
            break;
        }
    }
    
    return 0;
}
