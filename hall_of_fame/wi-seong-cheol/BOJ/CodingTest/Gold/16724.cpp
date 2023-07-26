//
//  16724.cpp
//  main
//
//  Created by wi_seong on 2023/03/10.
//

/*
 [Input]
 3 4
 DLLL
 DRLU
 RRRU
 [Output]
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16724

#include <iostream>

using namespace std;
int n, m, ans;
char board[1001][1001];
int vis[1001][1001];

void dfs(int x, int y) {
    vis[x][y] = true;
    int nx = x;
    int ny = y;
    if(board[x][y] == 'U')
        nx -= 1;
    else if(board[x][y] == 'D')
        nx += 1;
    else if(board[x][y] == 'L')
        ny -= 1;
    else
        ny += 1;

    if(vis[nx][ny] == 1) ans++;
    else if(vis[nx][ny] == 0) dfs(nx, ny);
    vis[x][y] = 2;
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
            if(!vis[i][j])
                dfs(i, j);
    cout << ans;
    
    return 0;
}
