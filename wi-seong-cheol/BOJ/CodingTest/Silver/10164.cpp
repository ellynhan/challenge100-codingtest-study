//
//  10164.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 7 11 76
 [Output]
 5005
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 225
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/10164

#include <iostream>

using namespace std;
int n, m, k, x, y;
int d[16][16];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    if(k == 0) k = n * m;
    x = k / m + (k % m != 0);
    y = k % m + (k % m == 0 ? m : 0);
    d[1][1] = 1;
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++) {
            if(i == 1 && j == 1) continue;
            d[i][j] = d[i - 1][j] + d[i][j - 1];
        }
    for(int i = x; i <= n; i++)
        for(int j = y; j <= m; j++) {
            if(i == x && j == y) continue;
            d[i][j] = d[i - 1][j] + d[i][j - 1];
        }
    cout << d[n][m];
    
    return 0;
}
