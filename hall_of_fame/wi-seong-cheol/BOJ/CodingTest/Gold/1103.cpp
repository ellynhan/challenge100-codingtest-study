//
//  1103.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/06.
//

/*
 [Input]
 3 7
 3942178
 1234567
 9123532
 [Output]
 5
 */
// 시간복잡도: O(n * m)
// 최악시간: 2,500
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1103

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
int n, m;
char board[51][51];
bool vis[51][51];
int d[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int dfs(int x, int y) {
    if(OOB(x, y) || board[x][y] == 'H')
        return 0;
 
    if(vis[x][y]) {
        cout << -1;
        exit(0);
    }
 
    int &ret = d[x][y];
    if(ret != -1)
        return ret;
 
    vis[x][y] = true;
 
    ret = 0;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir] * (board[x][y] - '0');
        int ny = y + dy[dir] * (board[x][y] - '0');
 
        ret = max(ret, dfs(nx, ny) + 1);
    }
 
    vis[x][y] = false;
    
    return ret;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    cout << dfs(0, 0);
    
    return 0;
}
