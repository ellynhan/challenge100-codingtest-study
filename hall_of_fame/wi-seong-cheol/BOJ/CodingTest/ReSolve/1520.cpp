//
//  1520.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 4 5
 50 45 37 32 30
 35 50 40 20 25
 30 30 25 17 28
 27 24 22 15 10
 [Output]
 3
 */
// 시간복잡도: O(n^2)
// 최악시간: 250,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1520

#include <iostream>
#include <queue>

using namespace std;
int n, m;
int board[501][501];
int d[501][501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int bfs(int x, int y) {
    if(x == n - 1 && y == m - 1)
        return 1;
    if(d[x][y] != -1) // 이미 방문한 적 있는 곳이면 dp 값 반환
        return d[x][y];
    d[x][y] = 0;
    
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || board[x][y] <= board[nx][ny]) continue;
        d[x][y] += bfs(nx, ny);
    }
    
    return d[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
            d[i][j] = -1;
        }
    cout << bfs(0, 0);
    
    return 0;
}
