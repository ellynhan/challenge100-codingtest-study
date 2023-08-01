//
//  1189.cpp
//  main
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 3 4 8
 ....
 .T..
 ....
 [Output]
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 25
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1189

#include <iostream>

using namespace std;
int ans;
int R, C, K;
char board[6][6];
bool vis[6][6];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= R || y < 0 || y >= C; }

void solve(int dist, int x, int y) {
    if(x == 0 && y == C - 1) {
        if(dist == K) ans++;
        return;
    }
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || vis[nx][ny]) continue;
        if(board[nx][ny] != '.') continue;
        vis[nx][ny] = true;
        solve(dist + 1, nx, ny);
        vis[nx][ny] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> R >> C >> K;
    for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
            cin >> board[i][j];
    vis[R - 1][0] = true;
    solve(1, R - 1, 0);
    cout << ans;
    
    return 0;
}
