//
//  15992.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 3
 4 2
 7 5
 10 6
 [Output]
 3
 15
 90
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15992

#include <iostream>

using namespace std;
#define ll long long
const int mod = 1e9 + 9;
int t, n, m;
ll d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1][1] = 1;
    d[2][1] = 1; d[2][2] = 1;
    d[3][1] = 1; d[3][2] = 2; d[3][3] = 1;
    for(int i = 4; i < 1001; i++)
        for(int j = 1; j <= i; j++)
            d[i][j] = ((d[i - 3][j - 1] + d[i - 2][j - 1]) % mod + d[i - 1][j - 1]) % mod;
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << d[n][m] << '\n';
    }
    
    return 0;
}
