//
//  10026.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/23.
//

/*
 [Input]
 5
 RRRBB
 GGBBB
 BBBRR
 BBRRR
 RRRRR
 [Output]
 4 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/10026

#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;
#define X first
#define Y second
int n;
int cnt1, cnt2;
char board[101][101];
bool vis[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void bfs(int x, int y, bool colorWeakness) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    int color = board[x][y];
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(colorWeakness) {
                if(color == 'B') {
                    if(board[nx][ny] != 'B') continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                } else {
                    if(board[nx][ny] == 'B') continue;
                    vis[nx][ny] = true;
                    Q.push({nx, ny});
                }
            } else {
                if(board[nx][ny] != color) continue;
                vis[nx][ny] = true;
                Q.push({nx, ny});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    
    // 일반인
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                cnt1++;
                bfs(i, j, false);
            }
        }
    
    memset(vis, false, sizeof(vis));
    // 색약
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                cnt2++;
                bfs(i, j, true);
            }
        }
    cout << cnt1 << ' ' << cnt2;
    
    return 0;
}
