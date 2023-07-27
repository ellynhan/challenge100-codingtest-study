//
//  .cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7 2 3
 [Output]
 7
 */
// 시간복잡도: O(logn)
// 최악시간: 12
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1351

#include <iostream>
#include <unordered_map>

using namespace std;
#define ll long long
ll n, p, q;
unordered_map<ll, ll> cache;

ll solve(ll n) {
    if(n == 0) return 1;
    ll& ret = cache[n];
    if(ret != 0) return ret;
    return ret = solve(n / p) + solve(n / q);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> p >> q;
    cout << solve(n);
    
    return 0;
}
