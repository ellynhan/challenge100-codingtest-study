//
//  2410.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/18.
//

/*
 [Input]
 2
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2410

#include <iostream>

using namespace std;
const int mod = 1e9;
int n;
int d[1000001];

void solve(int k, int num) {
    if(k > n) return;
    
    d[k] = (d[k] % mod + d[k - num] % mod) % mod;
    solve(k + 1, num);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 1;
    for(int i = 1; i <= n; i *= 2)
        solve(i, i);
    cout << d[n];
    
    return 0;
}
