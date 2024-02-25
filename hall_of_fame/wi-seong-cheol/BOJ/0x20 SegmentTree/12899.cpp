//
//  12899.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 5
 1 11
 1 29
 1 89
 2 2
 2 2
 [Output]
 29
 89
 */
// 시간복잡도: O(n)
// 최악시간: 10,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12899

#include <iostream>

using namespace std;
const int MXN = 2000001;
int n;
int tree[MXN * 4];

void update(int node, int nl, int nr, int val) {
    if(nl == nr) {
        tree[node]++;
        return;
    }
    int mid = (nl + nr) / 2;
    if(val <= mid) update(node * 2, nl, mid, val);
    else update(node * 2 + 1, mid + 1, nr, val);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int query(int node, int nl, int nr, int val) {
    if(nl == nr) {
        tree[node]--;
        return nl;
    }
    int ret = 0;
    int mid = (nl + nr) / 2;
    if(tree[node * 2] >= val) {
        ret = query(node * 2, nl, mid, val);
    } else {
        ret = query(node * 2 + 1, mid + 1, nr, val - tree[node * 2]);
    }
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if(a == 1) {
            update(1, 0, MXN - 1, b - 1);
        } else {
            cout << query(1, 0, MXN - 1, b) + 1<< '\n';
        }
    }

	return 0;
}
