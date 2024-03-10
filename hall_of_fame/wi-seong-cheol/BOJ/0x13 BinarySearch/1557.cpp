//
//  1557.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/25/24.
//

/*
 [Input]
 100
 [Output]
 163
 */
// 시간복잡도: O(nlogn)
// 최악시간: 1,000,000
// 난이도: Diamond 5
// Timer: 2h
// Url: https://www.acmicpc.net/problem/1557
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
#define ll long long
const int MXN = 200001;
int k;
vector<ll> mu(MXN, 0);

ll solve(ll x) {
    ll p = 0;
    for(ll i = 1; i * i <= x; i++) {
        p += mu[i] * (x / (i * i));
    }
    return p;
}
//
void seive() {
    mu[1] = 1;
    for(ll i = 1; i < MXN; ++i) {
        for(ll j = i + i; j < MXN; j += i) {
            mu[j] -= mu[i];
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();
    cin >> k;

    ll ans = 0;
    ll st = 0;
    ll en = k * 2;
    while(st <= en) {
        ll mid = (st + en + 1) / 2;

        if(solve(mid) < k) {
            st = mid + 1;
        } else {
            en = mid - 1;
            ans = mid;
        }
    }
    cout << ans;

    return 0;
}
