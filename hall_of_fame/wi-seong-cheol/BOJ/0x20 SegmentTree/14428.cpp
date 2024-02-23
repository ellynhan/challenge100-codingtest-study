//
//  14428.cpp
//  main
//
//  Created by wi_seong on 2/23/24.
//

/*
 [Input]
 5
 5 4 3 2 1
 6
 2 1 3
 2 1 4
 1 5 3
 2 3 5
 1 4 3
 2 3 5
 [Output]
 3
 4
 4
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 2,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14428

#include <iostream>
#include <climits>

using namespace std;
#define pii pair<int, int>
const int MXN = 100001;
int n, m;
pii tree[MXN * 4];
int arr[MXN];

pii minIndex(const pii &a, const pii &b) {
    if(a.first == b.first) {
        return a.second < b.second ? a : b;
    }
    return a.first < b.first ? a : b;
}

pii init(int node, int nl, int nr) {
    if(nl == nr) {
        return tree[node] = {arr[nl], nl};
    }
    int mid = (nl + nr) / 2;
    pii left = init(node * 2, nl, mid);
    pii right = init(node * 2 + 1, mid + 1, nr);
    return tree[node] = minIndex(left, right);
}

void update(int node, int nl, int nr, int idx, int val) {
    if(idx < nl || nr < idx) return;
    if(nl == nr) {
        tree[node] = {val, idx};
        return;
    }
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, idx, val);
    update(node * 2 + 1, mid + 1, nr, idx, val);
    tree[node] = minIndex(tree[node * 2], tree[node * 2 + 1]);
}

pii query(int node, int nl, int nr, int ql, int qr) {
    if(qr < nl || nr < ql) return {INT_MAX, 0};
    if(ql <= nl && nr <= qr) return tree[node];
    int mid = (nl + nr) / 2;
    pii left = query(node * 2, nl, mid, ql, qr);
    pii right = query(node * 2 + 1, mid + 1, nr, ql, qr);
    return minIndex(left, right);
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
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) {
            arr[b] = c;
            update(1, 1, n, b, c);
        } else {
            cout << query(1, 1, n, b, c).second << '\n';
        }
    }

	return 0;
}
