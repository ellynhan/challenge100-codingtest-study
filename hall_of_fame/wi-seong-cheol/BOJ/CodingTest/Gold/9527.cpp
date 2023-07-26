//
//  9527.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 2 12
 [Output]
 21
 */
// 시간복잡도: O(n)
// 최악시간: 150
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/9527

#include <iostream>

using namespace std;
#define ll long long
ll a, b;
ll d[55];

ll go(ll x) {
    ll ans = x & 1;
    
    for(ll i = 54; i > 0; i--) {
        if(x & (1LL << i)) {
            ans += d[i - 1] + (x - (1LL << i) + 1);
            x -= 1LL << i;
        }
    }
    
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    d[0] = 1;
    for(ll i = 1; i < 55; i++) {
        d[i] = d[i - 1] * 2 + (1LL << i);
    }
    cout << go(b) - go(a - 1);
    
    return 0;
}
