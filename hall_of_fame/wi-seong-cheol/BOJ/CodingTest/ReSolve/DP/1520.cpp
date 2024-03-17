//
//  1520.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
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
// 시간복잡도: O(n ^ 2)
// 최악시간: 25,000,000
// 난이도: Gold 3
// Timer: 6m
// Url: https://www.acmicpc.net/problem/1520

#include <iostream>
#include <cstring>

using namespace std;
int n, m;
int board[501][501];
int cache[501][501];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

int solve(int x, int y) {
    if(x == n - 1 && y == m - 1) return 1;
    int& ret = cache[x][y];
    if(ret != -1) return ret;
    ret = 0;
    for(int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(OOB(nx, ny)) continue;
        if(board[nx][ny] >= board[x][y]) continue;
        ret += solve(nx, ny);
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    memset(cache, -1, sizeof(cache));
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    cout << solve(0, 0);

	return 0;
}
