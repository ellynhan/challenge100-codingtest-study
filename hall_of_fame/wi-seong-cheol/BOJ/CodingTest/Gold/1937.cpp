//
//  1937.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 4
 14 9 12 10
 1 11 5 4
 7 15 2 13
 6 3 16 8
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1937

#include <iostream>
#include <algorithm>

using namespace std;
int n, ans;
int d[501][501];
int board[501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }

int move(int x, int y) {
    if(d[x][y] != 0) return d[x][y];
    d[x][y] = 1;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || board[nx][ny] <= board[x][y]) continue;
        d[x][y] = max(d[x][y], move(nx, ny) + 1);
    }
    
    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            ans = max(ans, move(i, j));
    cout << ans;
    
    return 0;
}
