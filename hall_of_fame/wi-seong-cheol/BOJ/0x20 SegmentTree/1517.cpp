//
//  1517.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/21/24.
//

/*
 [Input]
 3
 3 2 1
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 2,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1517

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;
#define ll long long
typedef pair<ll, ll> pll;
const int MXN = 5e5 + 1;
int n;
vector<pll> arr;
ll ans;
ll tree[2000006];

void update(ll node, ll nl, ll nr, ll idx) {
    if (nl == nr) { tree[node] = 1; return; }
    int mid = (nl + nr) >> 1;
    if (idx <= mid) update(2 * node, nl, mid, idx);
    else update(2 * node + 1, mid + 1, nr, idx);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(ll node, ll nl, ll nr, ll ql, ll qr) {
    if(nr < ql || qr < nl) return 0;
    if(ql <= nl && nr <= qr) return tree[node];
    ll mid = (nl + nr) >> 1;
    ll left = query(2 * node, nl, mid, ql, qr);
    ll right = query(2 * node + 1, mid + 1, nr, ql, qr);
    return left + right;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll val; cin >> val;
        arr.emplace_back(val, i);
    }
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++) {
        auto [val, idx] = arr[i];
        ans += query(1, 0, n - 1, idx + 1, n - 1);
        update(1, 0, n - 1, idx);
    }
    cout << ans;

    return 0;
}
