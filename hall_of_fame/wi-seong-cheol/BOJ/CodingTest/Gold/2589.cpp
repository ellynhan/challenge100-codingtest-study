//
//  2589.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 5 7
 WLLWWWL
 LLLWLLL
 LWLWLWW
 LWLWLLL
 WLLWLWW
 [Output]
 8
 */
// 시간복잡도: O((n * m) ^ 2)
// 최악시간: 6,250,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2589

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;
#define X first
#define Y second
int ans;
int n, m;
char board[51][51];
int dist[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int x, int y) {
    memset(dist, -1, sizeof(dist));
    queue<pair<int, int>> Q;
    Q.push({x, y});
    dist[x][y] = 0;
    int ret = 0;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        ret = max(ret, dist[cur.X][cur.Y]);
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(OOB(nx, ny) || dist[nx][ny] != -1) continue;
            if(board[nx][ny] != 'L') continue;
            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            Q.push({nx, ny});
        }
    }
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] = -1;
        }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(board[i][j] == 'L')
                ans = max(ans, bfs(i, j));
    cout << ans;
    
    return 0;
}
