//
//  15990.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 1 99999
 [Output]
 126356530
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15990

#include <iostream>

using namespace std;
#define ll long long
const int SIZE = 100'001;
const int mod = 1e9 + 9;
int t, n;
ll d[SIZE][4];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1][1] = 1;
    d[2][2] = 1;
    d[3][1] = 1; d[3][2] = 1; d[3][3] = 1;
    for(int i = 4; i < SIZE; i++) {
        d[i][1] = (d[i - 1][2] + d[i - 1][3]) % mod;
        d[i][2] = (d[i - 2][1] + d[i - 2][3]) % mod;
        d[i][3] = (d[i - 3][1] + d[i - 3][2]) % mod;
    }
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << (d[n][1] + d[n][2] + d[n][3]) % mod << '\n';
    }
    
    return 0;
}
