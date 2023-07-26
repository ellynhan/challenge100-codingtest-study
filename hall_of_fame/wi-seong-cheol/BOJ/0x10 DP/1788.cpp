//
//  1788.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 -2
 [Output]
 -1
 1
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1788

#include <iostream>
#include <algorithm>

using namespace std;
const int mod = 1e9;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 0; d[1] = 1;
    if(n >= 0) {
        for(int i = 2; i <= n; i++) {
            d[i] = (d[i - 1] + d[i - 2]) % mod;
        }
    } else {
        n = abs(n);
        for(int i = 2; i <= n; i++) {
            d[i] = (d[i - 2] - d[i - 1]) % mod;
        }
    }
    
    if(d[n] == 0) cout << 0 << '\n';
    else if(d[n] < 0) cout << -1 << '\n';
    else cout << 1 << '\n';
    cout << abs(d[n]);
    
    return 0;
}
