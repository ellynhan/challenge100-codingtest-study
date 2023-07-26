//
//  15991.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 3
 4
 7
 10
 [Output]
 3
 6
 20
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15991

#include <iostream>

using namespace std;
#define ll long long
const int mod = 1e9 + 9;
int t, n;
ll d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[0] = 1; d[1] = 1; d[2] = 2;
    d[3] = 2; d[4] = 3; d[5] = 3;
    for(int i = 6; i < 100001; i++)
        d[i] = ((d[i - 2] + d[i - 4]) % mod + d[i - 6]) % mod;
    
    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
