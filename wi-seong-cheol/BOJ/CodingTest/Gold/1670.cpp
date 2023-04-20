//
//  1670.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/20.
//

/*
 [Input]
 
 [Output]
 
 */
// 시간복잡도: O()
// 최악시간:
// 난이도:
// Timer:
// Url: https://www.acmicpc.net/problem/1670

#include <iostream>
#include <cstring>

using namespace std;
#define ll long long
const ll mod = 987654321;
ll n;
ll d[10001];

ll solve(ll k) {
    if(k % 2 == 1) return 0;
    if(k == 2 || k == 0) return 1;
    
    ll& ret = d[k];
    if(ret != -1) return ret;
    ret = 0;
    for(ll i = 2; i <= k; i += 2) {
        ret += (solve(i - 2) * solve(k - i));
        ret %= mod;
    }
    
    return ret % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, -1, sizeof(d));
    cin >> n;
    cout << solve(n);
    
    return 0;
}
