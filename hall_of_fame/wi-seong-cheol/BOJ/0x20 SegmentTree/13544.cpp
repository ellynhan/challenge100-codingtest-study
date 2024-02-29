//
//  13544.cpp
//  main
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 5
 5 1 2 3 4
 3
 2 4 1
 6 6 6
 1 5 2
 [Output]
 2
 0
 3
 */
// 시간복잡도: O(Q log2 N)
// 최악시간: 500,000
// 난이도: Platinum 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13544

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MXN = 100001;
int n, m;
int arr[MXN];
vector<int> tree[MXN * 4];

void update(int node, int nl, int nr, int idx, int val) {
    if(idx < nl || nr < idx) return;
    tree[node].push_back(val);
    if(nl == nr) return;
    int mid = (nl + nr) / 2;
    update(node * 2, nl, mid, idx, val);
    update(node * 2 + 1, mid + 1, nr, idx, val);
 }

int query(int node, int nl, int nr, int ql, int qr, int val) {
    if(qr < nl || nr < ql) return 0;
    if(ql <= nl && nr <= qr) {
        return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), val);
    }
    int mid = (nl + nr) / 2;
    int left = query(node * 2, nl, mid, ql, qr, val);
    int right = query(node * 2 + 1, mid + 1, nr, ql, qr, val);
    return left + right;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++) {
        int a; cin >> a;
        update(1, 1, n, i, a);
    }
    for(int i = 0; i <= MXN * 4; i++)
        sort(tree[i].begin(), tree[i].end());
    cin >> m;
    int prev = 0;
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        int result = query(1, 1, n, a ^ prev, b ^ prev, c ^ prev);
        prev = result;
        cout << result << '\n';
    }

	return 0;
}
