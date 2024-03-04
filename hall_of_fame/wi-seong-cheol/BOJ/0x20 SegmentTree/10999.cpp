//
//  10999.cpp
//  main
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 5 2 2
 1
 2
 3
 4
 5
 1 3 4 6
 2 2 5
 1 1 3 -2
 2 2 5
 [Output]
 26
 22
 */
// 시간복잡도: O(n)
// 최악시간: 4,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/10999

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
const int MXN = 1000001;
int n, m, k;
ll tree[MXN * 4], lazy[MXN * 4], arr[MXN];

void init(int node, int nl, int nr) {
    if(nl == nr) {
        tree[node] = arr[nl];
        return;
    }
    int mid = (nl + nr) / 2;
    init(node * 2, nl, mid);
    init(node * 2 + 1, mid + 1, nr);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void propagation(int node, int nl, int nr) {
    if(lazy[node] == 0) return;
    tree[node] += lazy[node] * (nr - nl + 1);
    if(nl != nr) {
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int nl, int nr, int ql, int qr, ll val) {
    propagation(node, nl, nr);
    if(qr < nl || nr < ql) return;
    if(ql <= nl && nr <= qr) {
        lazy[node] += val;
        propagation(node, nl, nr);
        return;
    }
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, ql, qr, val);
    update(node * 2 + 1, mid + 1, nr, ql, qr, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

ll query(int node, int nl, int nr, int ql, int qr) {
    propagation(node, nl, nr);
    if(qr < nl || nr < ql) return 0;
    if(ql <= nl && nr <= qr) return tree[node];
    int mid = (nl + nr) / 2;
    ll left = query(node * 2, nl, mid, ql, qr);
    ll right = query(node * 2 + 1, mid + 1, nr, ql, qr);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);

    for(int i = 0; i < m + k; i++) {
        int a, b, c;
        cin >> a >> b >> c;;
        if(b > c) swap(b, c);
        if(a == 1) {
            ll d; cin >> d;
            update(1, 1, n, b, c, d);
        } else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }

	return 0;
}
