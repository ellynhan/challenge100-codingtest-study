//
//  17408.cpp
//  main
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 5
 5 4 3 2 1
 6
 2 2 4
 2 1 4
 1 5 5
 2 3 5
 1 4 9
 2 3 5
 [Output]
 7
 9
 8
 14
 */
// 시간복잡도: O(n)
// 최악시간: 500,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17408

#include <iostream>
#include <algorithm>

using namespace std;
#define pii pair<int, int>
const int MXN = 100001;
int n, m;
pii tree[MXN * 4];
int arr[MXN];

pii get_max_pair(const pii& a, const pii& b) {
    if(a.first >= b.first) {
        return {a.first, max(a.second, b.first)};
    }
    return {b.first, max(b.second, a.first)};
}

void init(int node, int nl, int nr) {
    if(nl == nr) {
        tree[node] = {arr[nl], 0};
        return;
    }
    int mid = (nl + nr) / 2;
    init(node * 2, nl, mid);
    init(node * 2 + 1, mid + 1, nr);
    tree[node] = get_max_pair(tree[node * 2], tree[node * 2 + 1]);
}

void update(int node, int nl, int nr, int idx, int val) {
    if(idx < nl || nr < idx) return;
    if(nl == nr) {
        tree[node].first = {arr[idx] = val};
        return;
    }
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, idx, val);
    update(node * 2 + 1, mid + 1, nr, idx, val);
    tree[node] = get_max_pair(tree[node * 2], tree[node * 2 + 1]);
}

pii query(int node, int nl, int nr, int ql, int qr) {
    if(qr < nl || nr < ql) return {0, 0};
    if(ql <= nl && nr <= qr) return tree[node];
    int mid = (nl + nr) / 2;
    pii left = query(node * 2, nl, mid, ql, qr);
    pii right = query(node * 2 + 1, mid + 1, nr, ql, qr);
    return get_max_pair(left, right);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    init(1, 1, n);
    cin >> m;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            update(1, 1, n, b, c);
        } else {
            pii ans = query(1, 1, n, b, c);
            cout << ans.first + ans.second << '\n';
        }
    }

	return 0;
}
