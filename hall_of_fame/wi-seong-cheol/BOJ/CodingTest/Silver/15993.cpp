//
//  15993.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 3
 4
 7
 10
 [Output]
 3 4
 22 22
 137 137
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/15993

#include <iostream>

using namespace std;
#define ll long long
const int mod = 1e9 + 9;
int t, n;
ll d[100001][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1][1] = 1;
    d[2][1] = 1; d[2][0] = 1;
    d[3][1] = 2; d[3][0] = 2;
    for(int i = 4; i < 100001; i++) {
        d[i][1] = ((d[i - 1][0] + d[i - 2][0]) % mod + d[i - 3][0]) % mod;
        d[i][0] = ((d[i - 1][1] + d[i - 2][1]) % mod + d[i - 3][1]) % mod;
    }
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n][1] << ' ' << d[n][0] << '\n';
    }
    
    return 0;
}
