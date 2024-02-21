//
//  7626.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/21/24.
//

/*
 [Input]
 2
 0 3 1 2
 1 2 0 3
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 1,600,000
// 난이도: Platinum 1
// Timer: 2h
// Url: https://www.acmicpc.net/problem/7626

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
typedef tuple<ll, ll, ll, ll> tp;
const ll MAXN = 4e5 + 1;
ll n, ans;
vector<tp> edge;
vector<ll> ySet;
ll cnt[MAXN << 2], tree[MAXN << 2];

void update(ll node, ll nl, ll nr, ll ql, ll qr, ll val) {
    if(qr < nl || nr < ql) return;
    if(ql <= nl && nr <= qr) tree[node] += val;
    else {
        ll mid = (nl + nr) / 2;
        update(node * 2, nl, mid, ql, qr, val);
        update(node * 2 + 1, mid + 1, nr, ql, qr, val);
    }
    cnt[node] = tree[node] ? ySet[nr] - ySet[nl - 1] : nl ^ nr ? cnt[node * 2] + cnt[node * 2 + 1] : 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        edge.emplace_back(a, c + 1, d + 1, 1);
        edge.emplace_back(b, c + 1, d + 1, -1);
        ySet.push_back(c + 1);
        ySet.push_back(d + 1);
    }
    sort(ySet.begin(), ySet.end());
    ySet.erase(unique(ySet.begin(), ySet.end()), ySet.end());
    sort(edge.begin(), edge.end());

    ll prv = 0;
    for(int i = 0; i < n * 2; i++) {
        auto [x, y1, y2, val] = edge[i];
        if(i) ans += (x - prv) * cnt[1];
        prv = x;
        ll qs = lower_bound(ySet.begin(), ySet.end(), y1) - ySet.begin();
        ll qe = lower_bound(ySet.begin(), ySet.end(), y2) - ySet.begin();
        update(1, 1, MAXN, qs + 1, qe, val);
    }
    cout << ans;

    return 0;
}
