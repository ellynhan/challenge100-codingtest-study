//
//  14430.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 5 4
 0 1 0 0
 0 0 1 0
 1 1 0 0
 1 0 1 0
 1 1 0 0
 [Output]
 4
 */
// 시간복잡도: O(n^2)
// 최악시간: 90,000
// 난이도: Silver 2
// Timer: 20m
// Url: https://www.acmicpc.net/problem/14430

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[301][301];
int d[301][301];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = max(d[i - 1][j], d[i][j - 1]) + board[i][j];
    cout << d[n][m];
    
    return 0;
}
