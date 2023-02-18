//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 4
 7
 10
 [Output]
 7
 44
 274
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/15988

#include <iostream>

using namespace std;
const int MX = 1000001;
const int mod = 1e9 + 9;
int t, n;
int d[MX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    
    d[1] = 1; d[2] = 2; d[3] = 4;
    for(int i = 4; i < MX; i++)
        for(int j = 1; j <= 3; j++)
            d[i] = (d[i] + d[i - j]) % mod;
    
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
