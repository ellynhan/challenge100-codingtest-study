//
//  2268.cpp
//  main
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 3 5
 0 1 3
 1 1 2
 1 2 3
 0 2 3
 0 1 3
 [Output]
 0
 3
 5
 */
// 시간복잡도: O(n)
// 최악시간: 4,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2268

#include <iostream>

using namespace std;
#define ll long long
const int MXN = 1000001;
int n, m;
ll tree[MXN * 4], arr[MXN] = {};

ll init(int node, int nl, int nr) {
    if(nl == nr) {
        return tree[node] = 0;
    }
    int mid = (nl + nr) / 2;
    ll left = init(node * 2, nl, mid);
    ll right = init(node * 2 + 1, mid + 1, nr);
    return tree[node] = left + right;
}

void update(int node, int nl, int nr, int idx, ll val) {
    if(idx < nl || nr < idx) return;
    tree[node] += val;
    if(nl == nr) return;
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, idx, val);
    update(node * 2 + 1, mid + 1, nr, idx, val);
}

ll query(int node, int nl, int nr, int ql, int qr) {
    if(qr < nl || nr < ql) return 0;
    if(ql <= nl && nr <= qr) return tree[node];
    int mid = (nl + nr) / 2;
    ll left = query(node * 2, nl, mid, ql, qr);
    ll right = query(node * 2 + 1, mid + 1, nr, ql, qr);
    return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    init(1, 1, n);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0) {
            if(b > c) swap(b, c);
            cout << query(1, 1, n, b, c) << '\n';
        } else {
            update(1, 1, n, b, c - arr[b - 1]);
            arr[b - 1] = c;
        }
    }

	return 0;
}
