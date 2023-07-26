//
//  11048.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/13.
//

/*
 [Input]
 4 3
 1 2 3
 6 5 4
 7 8 9
 12 11 10
 [Output]
 47
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 5m
// Url: https://www.acmicpc.net/problem/11048

#include <iostream>
#include <algorithm>

using namespace std;
int n, m;
int board[1001][1001];
int d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            d[i][j] = max({d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]}) + board[i][j];
    cout << d[n][m];
    
    return 0;
}
