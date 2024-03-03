//
//  2243.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 6
 2 1 2
 2 3 3
 1 2
 1 2
 2 1 -1
 1 2
 [Output]
 1
 3
 3
 */
// 시간복잡도: O(n)
// 최악시간: 4,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2243

#include <iostream>

using namespace std;
const int MXN = 1000001;
int n;
int tree[MXN * 4];

void update(int node, int nl, int nr, int idx, int val) {
    if(idx < nl || nr < idx) return;
    tree[node] += val;
    if(nl == nr) return;
    int mid = (nl + nr) / 2;
    if(idx <= mid) update(node * 2, nl, mid, idx, val);
    else update(node * 2 + 1, mid + 1, nr, idx, val);
}

int query(int node, int nl, int nr, int rank) {
    if(nl == nr) return nl;
    int mid = (nl + nr) / 2;
    if(tree[node * 2] >= rank)
        return query(node * 2, nl, mid, rank);
    return query(node * 2 + 1, mid + 1, nr, rank - tree[node * 2]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a;
        if(a == 1) {
            cin >> b;
            int ret = query(1, 1, MXN, b);
            cout << ret << '\n';
            update(1, 1, MXN, ret, -1);
        } else {
            cin >> b >> c;
            update(1, 1, MXN, b, c);
        }
    }

	return 0;
}
