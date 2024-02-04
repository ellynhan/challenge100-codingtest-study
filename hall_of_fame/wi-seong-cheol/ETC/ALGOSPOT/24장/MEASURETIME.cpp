//
//  MEASURETIME.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 2
 5
 5 1 4 3 2
 10
 7 8 6 6 1 9 4 4 3 10
 [Output]
 7
 10
 */
// 시간복잡도: O(nlgm)
// 최악시간: 300,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/MEASURETIME

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
struct FenwickTree {
    vector<int> tree;
    FenwickTree(int n) : tree(n + 1) {}

    int sum(int pos) {
        ++pos;
        int ret = 0;
        while(pos > 0) {
            ret += tree[pos];
            pos &= (pos - 1);
        }
        return ret;
    }

    void add(int pos, int val) {
        ++pos;
        while(pos < tree.size()) {
            tree[pos] += val;
            pos += (pos & -pos);
        }
    }
};
int t, n;
int a[500000];

ll countMoves() {
    ll ret = 0;
    FenwickTree tree(1000000);
    for(int i = 0; i < n; i++) {
        ret += tree.sum(999999) - tree.sum(a[i]);
        tree.add(a[i], 1);
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) cin >> a[i];
        cout << countMoves() << '\n';
    }

	return 0;
}
