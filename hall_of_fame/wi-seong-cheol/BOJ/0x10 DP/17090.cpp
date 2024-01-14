//
//  17090.cpp
//  main
//
//  Created by wi_seong on 1/4/24.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O()
// 최악시간: 
// 난이도: 
// Timer: 
// Url: https://www.acmicpc.net/problem/17090

#include <iostream>
#include <unordered_map>

using namespace std;
int n, m;
string board[501];
int dp[501][501];
unordered_map<char, int> dir = {{'U', 0}, {'R', 1}, {'D', 2}, {'L', 3}};
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= m; }

void init() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = -1;
}

int solve(int x, int y) {
    if(OOB(x, y)) return 1;
    if(dp[x][y] != -1) return dp[x][y];

    int d = dir[board[x][y]];
    int nx = x + dx[d];
    int ny = y + dy[d];
    dp[x][y] = 0;
    return dp[x][y] = solve(nx, ny);
}

int count() {
    int cnt = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cnt += dp[i][j];
    return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> board[i];
    init();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            solve(i, j);
    cout << count();

	return 0;
}
