//
//  1697.cpp
//  main
//
//  Created by wi_seong on 2022/11/14.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O(n * n)
// 최악시간: 10,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10026

#include <iostream>
#include <queue>
#include <string>

using namespace std;
#define X first
#define Y second
const int SIZE = 101;
int n;
string board[SIZE];
bool vis[SIZE][SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    
    queue<pair<int, int>> Q;
    int cnt1, cnt2;
    cnt1 = cnt2 = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                cnt1++;
                Q.push({i, j});
                vis[i][j] = true;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx, ny) || vis[nx][ny]) continue;
                        if(board[nx][ny] != board[cur.X][cur.Y]) continue;
                        vis[nx][ny] = true;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
        fill(vis[i], vis[i] + SIZE, false);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(!vis[i][j]) {
                cnt2++;
                Q.push({i, j});
                vis[i][j] = true;
                while(!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(OOB(nx, ny) || vis[nx][ny]) continue;
                        if(board[cur.X][cur.Y] == 'B') {
                            if(board[nx][ny] != 'B') continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        } else {
                            if(board[nx][ny] == 'B') continue;
                            vis[nx][ny] = true;
                            Q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout << cnt1 << ' ' << cnt2;
    
    return 0;
}
