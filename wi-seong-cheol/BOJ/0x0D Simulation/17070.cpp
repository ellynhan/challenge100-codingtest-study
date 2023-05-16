//
//  17070.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 4
 0 0 0 0
 0 0 0 0
 0 0 0 0
 0 0 0 0
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 400
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/17070

#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
int n, ans;
int board[21][21];
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

void solve(int x, int y, int prev_dir) {
    if(x == n - 1 && y == n - 1) {
        ans++;
        return;
    }
    
    for(int dir = 0; dir < 3; dir++) {
        if(prev_dir == 0 && dir == 2) continue;
        if(prev_dir == 2 && dir == 0) continue;
        
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || board[nx][ny]) continue;
        if(dir == 1) {
            if(board[nx][y] || board[x][ny]) continue;
        }
        solve(nx, ny, dir);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    solve(0, 1, 0);
    cout << ans;
    
    return 0;
}
