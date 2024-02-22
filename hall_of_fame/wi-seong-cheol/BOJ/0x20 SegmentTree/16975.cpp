//
//  16975.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 5
 1 2 3 4 5
 4
 1 3 4 6
 2 3
 1 1 3 -2
 2 3
 [Output]
 9
 7
 */
// 시간복잡도: O(n)
// 최악시간: 4,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/16975

#include <iostream>
#include <climits>
using namespace std;
#define ll long long
const int MXN = 1000001;
int n, m;
ll v[MXN], tree[MXN * 4];

void init(ll node, ll nl, ll nr) {
    if(nl == nr) {
        tree[node] = v[nl];
        return;
    }
    ll mid = (nl + nr) / 2;
    tree[node] = 0;
    init(node * 2, nl, mid);
    init(node * 2 + 1, mid + 1, nr);
}

void update(ll node, ll nl, ll nr, ll ql, ll qr, ll val) {
    if(qr < nl || nr < ql) return;
    if(ql <= nl && nr <= qr) {
        tree[node] += val;
        return;
    }
    ll mid = (nl + nr) / 2;
    update(node * 2, nl, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, nr, ql, qr, val);
}

ll query(ll node, ll nl, ll nr, ll ql, ll qr, ll ans) {
    if(qr < nl || nr < ql) return 0;
    if(nl == nr) return ans;
    ll mid = (nl + nr) / 2;
    ll left = query(node * 2, nl, mid, ql, qr, ans);
    ll right = query(node * 2 + 1, mid + 1, nr, ql, qr, ans);
    return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    init(1, 0, n - 1);

    cin >> m;
    for(int i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a;
        if(a == 1) {
            cin >> b >> c >> d;
            update(1, 0, n - 1, b - 1, c - 1, d);
        } else {
            cin >> b;
            cout << query(1, 0, n - 1, b - 1, b - 1, 0) << '\n';
        }
    }

	return 0;
}
