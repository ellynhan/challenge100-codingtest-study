//
//  1915.cpp
//  main
//
//  Created by wi_seong on 3/14/24.
//

/*
 [Input]
 4 4
 0100
 0111
 1110
 0010
 [Output]
 4
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 12m
// Url: https://www.acmicpc.net/problem/1915

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
char board[1001][1001];
int dp[1001][1001];

int solve() {
    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(board[i][j] == '1') {
                dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
                ret = max(ret, dp[i][j]);
            }
        }
    }

    return ret * ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> board[i][j];
        }
    }
    cout << solve();

	return 0;
}
