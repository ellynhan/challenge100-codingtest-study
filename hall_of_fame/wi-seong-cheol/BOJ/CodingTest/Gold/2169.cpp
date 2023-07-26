//
//  2169.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 5 5
 10 25 7 8 13
 68 24 -78 63 32
 12 -69 100 -29 -25
 -16 -22 -57 -33 99
 7 -76 -11 77 15
 [Output]
 319
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2169

#include <iostream>
#include <cstring>

using namespace std;
#define MIN -987654321
int n, m;
int board[1001][1001];
bool vis[1001][1001];
int cost[1001][1001][3];
int dx[] = {0, 0, 1};
int dy[] = {1, -1, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int dfs(int x, int y, int d) {
    if(x == n - 1 && y == m - 1) return board[x][y];
    if(cost[x][y][d] != MIN) return cost[x][y][d];
    int val = MIN;
    
    vis[x][y] = true;
    for(int dir = 0; dir < 3; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny) || vis[nx][ny]) continue;
        val = max(val, dfs(nx, ny, dir));
    }
    vis[x][y] = false;
    cost[x][y][d] = board[x][y] + val;
    
    return cost[x][y][d];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cost[i][j][0] = MIN;
            cost[i][j][1] = MIN;
            cost[i][j][2] = MIN;
        }
    
    cout << dfs(0, 0, 0);
    
    return 0;
}
