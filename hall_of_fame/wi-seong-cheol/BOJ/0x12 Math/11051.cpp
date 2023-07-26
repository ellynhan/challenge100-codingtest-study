//
//  11051.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 5 2
 [Output]
 10
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11051

#include <iostream>

using namespace std;
const int mod = 10007;
int n, m;
int comb[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        comb[i][0] = comb[i][i] = 1;
        for(int j = 1; j < i; j++)
            comb[i][j] = (comb[i-1][j] + comb[i-1][j - 1]) % mod;
    }
    cout << comb[n][m];
    
    return 0;
}
