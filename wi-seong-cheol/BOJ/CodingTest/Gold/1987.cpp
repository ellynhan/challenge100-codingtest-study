//
//  1987.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 2 4
 CAAB
 ADCB
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 400
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1987

#include <iostream>
#include <algorithm>

using namespace std;
int n, m, ans;
bool vis[26];
char board[21][21];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void dfs(int x, int y, int len) {
    ans = max(ans, len);
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(vis[board[nx][ny] - 'A']) continue;
        vis[board[nx][ny] - 'A'] = true;
        dfs(nx, ny, len + 1);
        vis[board[nx][ny] - 'A'] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    vis[board[0][0] - 65] = true;
    dfs(0, 0, 1);
    cout << ans;
    
    return 0;
}
