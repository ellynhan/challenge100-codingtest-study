//
//  22953.cpp
//  main
//
//  Created by wi_seong on 1/8/24.
//

/*
 [Input]
 2 200 1
 100 101
 [Output]
 9999
 */
// 시간복잡도: O(2^c * (k * Ai)log(k * Ai))
// 최악시간: 384
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/22953

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define MAX 98760000000000
ll ans = MAX;
int n, k, c;
vector<ll> a;

bool possible(ll mid) {
    ll cnt = 0;
    for(int i = 0; i < n; i++) {
        cnt += mid / a[i];
    }
    return cnt >= k;
}

void binary_search() {
    ll st = 1;
    ll en = MAX;
    ll mid;

    while(st <= en) {
        mid = (st + en) / 2;

        if(possible(mid)) {
            ans = min(ans, mid);
            en = mid - 1;
        } else {
            st = mid + 1;
        }
    }
}

void solve(int k) {
    if(k == c) {
        binary_search();
        return;
    }

    binary_search();
    for(int i = 0; i < n; i++) {
        if(a[i] == 1) continue;
        a[i]--;
        solve(k + 1);
        a[i]++;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k >> c;
    for(int i = 0; i < n; i++) {
        ll x; cin >> x;
        a.push_back(x);
    }
    solve(0);
    cout << ans;

	return 0;
}
