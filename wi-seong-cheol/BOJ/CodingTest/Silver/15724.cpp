//
//  15724.cpp
//  main
//
//  Created by wi_seong on 2023/02/25.
//

/*
 [Input]
 4 4
 9 14 29 7
 1 31 6 13
 21 26 40 16
 8 38 11 23
 3
 1 1 3 2
 1 1 1 4
 1 1 4 4
 [Output]
 102
 59
 293
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,048,576
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/15724

#include <iostream>

using namespace std;
int n, m, k, a, b, c, d;
int board[1025][1025];
int dp[1025][1025];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + board[i][j] - dp[i - 1][j - 1];
    cin >> k;
    while(k--) {
        cin >> a >> b >> c >> d;
        cout << dp[c][d] - dp[c][b - 1] - dp[a - 1][d] + dp[a - 1][b - 1] << '\n';
    }
    
    return 0;
}
