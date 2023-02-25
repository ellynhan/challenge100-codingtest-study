//
//  14503.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/11/23.
//

/*
 [Input]
 11 10
 7 4 0
 1 1 1 1 1 1 1 1 1 1
 1 0 0 0 0 0 0 0 0 1
 1 0 0 0 1 1 1 1 0 1
 1 0 0 1 1 0 0 0 0 1
 1 0 1 1 0 0 0 0 0 1
 1 0 0 0 0 0 0 0 0 1
 1 0 0 0 0 0 0 1 0 1
 1 0 0 0 0 0 1 1 0 1
 1 0 0 0 0 0 1 1 0 1
 1 0 0 0 0 0 0 0 0 1
 1 1 1 1 1 1 1 1 1 1
 [Output]
 57
 */
// 시간복잡도: O(n * m)
// 최악시간: 250
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14503

#include <iostream>

using namespace std;

int n, m, src_y, src_x, src_d, ans;
int board[55][55];
int vis[55][55];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int solve(int x, int y, int d){
    vis[x][y] = 1;
    bool isClean = true;
    
    for(int i = 0; i < 4; i++) {
        int left = d-1 >= 0 ? d-1 : 3;
        int nx = x + dx[left];
        int ny = y + dy[left];
        d = left;
        if(board[nx][ny] || vis[nx][ny] || OOB(x, y)) continue;
        if(solve(nx, ny, d) == -1) return -1;
        isClean = false;
    }
    if(isClean){
        int nx = x - dx[d];
        int ny = y - dy[d];
        if(board[nx][ny] || OOB(x, y)) {
            return -1;
        } else {
            if(solve(nx, ny, d) == -1) return -1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> src_x >> src_y >> src_d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    
    solve(src_x, src_y, src_d);
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans += vis[i][j];
    cout << ans;
    
    return 0;
}
