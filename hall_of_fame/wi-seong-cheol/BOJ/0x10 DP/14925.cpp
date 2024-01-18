//
//  14925.cpp
//  main
//
//  Created by wi_seong on 1/9/24.
//

/*
 [Input]
 6 6
 0 0 0 1 0 0
 0 0 0 2 1 0
 0 0 2 0 0 0
 0 1 0 0 0 0
 2 0 0 0 0 0
 0 0 0 0 0 0
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 10m
// Url: https://www.acmicpc.net/problem/14925

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[1001][1001];
int d[1001][1001];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) 
            cin >> board[i][j];
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] != 0) continue;
            d[i][j] = min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
            ans = max(ans, d[i][j]);
        }
    }
    cout << ans;

	return 0;
}
