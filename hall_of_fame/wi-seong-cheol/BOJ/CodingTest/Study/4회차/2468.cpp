//
//  2468.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 7
 9 9 9 9 9 9 9
 9 2 1 2 1 2 9
 9 1 8 7 8 1 9
 9 2 7 9 7 2 9
 9 1 8 7 8 1 9
 9 2 1 2 1 2 9
 9 9 9 9 9 9 9
 [Output]
 6
 */
// 시간복잡도: O(N * M * H)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/2468

#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans = 1;
int mxHeight, mnHeight = 0x7f7f7f7f;
int n;
int board[101][101];
bool vis[101][101];
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
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> board[i][j];
            mnHeight = min(mnHeight, board[i][j]);
            mxHeight = max(mxHeight, board[i][j]);
        }
    
    for(int h = mnHeight; h < mxHeight; h++) {
        int cnt = 0;
        memset(vis, false, sizeof(vis));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(!vis[i][j] && board[i][j] > h) {
                    cnt++;
                    bfs(i, j, h);
                }
        ans = max(ans, cnt);
    }
    
    cout << ans;
    
    return 0;
}
