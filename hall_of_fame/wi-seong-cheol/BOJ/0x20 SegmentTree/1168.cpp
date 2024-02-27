//
//  1168.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2/22/24.
//

/*
 [Input]
 7 3
 [Output]
 <3, 6, 2, 7, 5, 1, 4>
 */
// 시간복잡도: O(n)
// 최악시간: 400,000
// 난이도: Platinum 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1168

#include <iostream>
#include <vector>

using namespace std;
const int MXN = 100001;
int n, k;
int tree[MXN * 4];
vector<int> ans;

int get_num_and_update(int node, int nl, int nr, int idx) {
    tree[node]--;
    if(nl == nr) return nl;
    int mid = (nl + nr) / 2;
    if(idx <= tree[node * 2]) return get_num_and_update(node * 2, nl, mid, idx);
    return get_num_and_update(node * 2 + 1, mid + 1, nr, idx - tree[node * 2]);
}

int init(int node, int nl, int nr) {
    if(nl == nr) return tree[node] = 1;
    int mid = (nl + nr) / 2;
    int left = init(node * 2, nl, mid);
    int right = init(node * 2 + 1, mid + 1, nr);
    return tree[node] = left + right;
}

void print() {
    cout << "<" << ans[0];
    for(int i = 1; i < n; i++) {
        cout << ", " << ans[i];
    }
    cout << ">";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> k;
    init(1, 1, n);

    int idx = k - 1;
    for(int i = 0; i < n; i++) {
        int get_idx = get_num_and_update(1, 1, n, idx + 1);
        ans.push_back(get_idx);
        if(tree[1] == 0) break;
        idx += k - 1;
        idx %= tree[1];
    }
    print();

	return 0;
}
