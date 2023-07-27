//
//  17484.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/01.
//

/*
 [Input]
 6 4
 5 8 5 1
 3 5 8 4
 9 77 65 5
 2 1 5 2
 5 98 1 5
 4 95 67 58
 [Output]
 29
 */
// 시간복잡도: O(n * 2 ^ n )
// 최악시간: 512
// 난이도: Silver 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/17484

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int ans = INF;
int n, m;
int board[8][8];
int dy[] = {-1, 0, 1};

void solve(int x, int y, int prev, int sum) {
    if(x == n - 1) {
        ans = min(ans, sum);
        return;
    }
    for(int dir = 0; dir < 3; dir++) {
        if(dir == prev) continue;
        int nx = x + 1;
        int ny = y + dy[dir];
        if(ny < 0 || ny >= m) continue;
        solve(nx, ny, dir, sum + board[nx][ny]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];
    for(int i = 0; i < m; i++)
        solve(0, i, -1, board[0][i]);
    cout << ans;
    
    return 0;
}
