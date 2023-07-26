//
//  2636.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/13.
//

/*
 [Input]
 3 3
 0 0 0
 0 1 0
 0 0 0
 [Output]
 1
 1
 */
// 시간복잡도: O(n * m * (n / 2))
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/

#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
#define X first
#define Y second
int n, m;
int t, remain;
int board[101][101];
bool vis[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || vis[nx][ny]) continue;
            if(board[nx][ny] == 1) {
                board[nx][ny] = 0;
            } else {
                Q.push({nx, ny});
            }
            vis[nx][ny] = true;
        }
    }
}

int countCheese() {
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += board[i][j];
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    while(1) {
        remain = countCheese();
        memset(vis, false, sizeof(vis));
        t++;
        bfs(0, 0);
        if(countCheese() == 0) break;
    }
    cout << t << '\n' << remain;
    
    return 0;
}
