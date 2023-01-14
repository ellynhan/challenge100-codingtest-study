//
//  27211.cpp
//  main
//
//  Created by wi_seong on 2023/01/14.
//

/*
 [Input]
 5 6
 1 1 1 1 1 1
 1 0 0 0 1 1
 1 1 1 1 0 0
 1 1 1 1 0 0
 1 1 1 1 1 1
 [Output]
 2
 */
// 시간복잡도: O()
// 최악시간:
// 난이도:
// Timer:
// Url: https://www.acmicpc.net/problem/27211

#include <iostream>
#include <queue>

using namespace std;
#define X first
#define Y second
int n, m, ans;
int board[1001][1001];
bool vis[1001][1001];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void bfs(int x, int y) {
    queue<pair<int, int>> Q;
    Q.push({x, y});
    vis[x][y] = true;
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx >= n) nx = 0;
            if(nx < 0) nx = n - 1;
            if(ny >= m) ny = 0;
            if(ny < 0) ny = m - 1;
            if(vis[nx][ny] || board[nx][ny] == 1) continue;
            Q.push({nx, ny});
            vis[nx][ny] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(!vis[i][j] && board[i][j] == 0) {
                ans++;
                bfs(i, j);
            }
    cout << ans;
    
    return 0;
}

