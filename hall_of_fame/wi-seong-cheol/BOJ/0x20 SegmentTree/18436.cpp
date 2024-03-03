//
//  18436.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 6
 1 2 3 4 5 6
 4
 2 2 5
 3 1 4
 1 5 4
 2 1 6
 [Output]
 2
 2
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 20,000,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/18436

#include <iostream>

using namespace std;
#define pii pair<int, int>
const int MXN = 100001;
int n, m;
int tree[MXN * 4];
int arr[MXN];

int init(int node, int nl, int nr) {
    if(nl == nr) {
        return tree[node] = arr[nl] % 2 == 0 ? 0 : 1;
    }
    int mid = (nl + nr) / 2;
    int left = init(node * 2, nl, mid);
    int right = init(node * 2 + 1, mid + 1, nr);
    return tree[node] = left + right;
}

void update(int node, int nl, int nr, int idx, int x, int val) {
    if(idx < nl || nr < idx) return;
    x % 2 ? tree[node]++ : tree[node]--;
    if(nl == nr) {
        tree[node] = val;
        return;
    }
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, idx, x, val);
    update(node * 2 + 1, mid + 1, nr, idx, x, val);
}

int query(int node, int nl, int nr, int ql, int qr) {
    if(qr < nl || nr < ql) return 0;
    if(ql <= nl && nr <= qr)
        return tree[node];
    int mid = (nl + nr) / 2;
    int left = query(node * 2, nl, mid, ql, qr);
    int right = query(node * 2 + 1, mid + 1, nr, ql, qr);
    return left + right;
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
    while(m--) {
        int a, b, c; cin >> a >> b >> c;
        if(a == 1) {
            if(arr[b] % 2 != c % 2) update(1, 1, n, b, c, c % 2);
            arr[b] = c;
        } else if(a == 2) {
            int len = c - b + 1;
            cout << len - query(1, 1, n, b, c) << '\n';
        } else {
            cout << query(1, 1, n, b, c) << '\n';
        }
    }

	return 0;
}
