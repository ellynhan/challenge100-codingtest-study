//
//  MORDOR.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 2
 3 1
 1 2 3
 0 2
 10 4
 3 9 5 6 10 8 7 1 2 4
 1 6
 4 7
 9 9
 5 8
 [Output]
 2
 5
 9
 0
 7
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/MORDOR

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
struct RMQ {
    int n;

    vector<int> rangeMin;

    RMQ(const vector<int>& array) {
        n = int(array.size());
        rangeMin.resize(n * 4);
        init(array, 0, n - 1, 1);
    }

    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right) return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node * 2);
        int rightMin = init(array, mid + 1, right, node * 2 + 1);
        return rangeMin[node] = min(leftMin, rightMin);
    }
    
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || nodeRight < left) return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right) return rangeMin[node];
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node * 2 + 1, mid + 1, nodeRight));
    }
    
    int query(int left, int right) {
        return query(left, right, 1, 0, n - 1);
    }
};
int t, n, q, a, b;
vector<int> h;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        h.resize(n);
        for(int i = 0; i < n; i++) cin >> h[i];
        RMQ rmq(h);
        for(int i = 0; i < n; i++) h[i] *= -1;
        RMQ rmq2(h);

        for(int i = 0; i < q; i++) {
            cin >> a >> b;
            cout << (-1 * (rmq.query(a, b) + rmq2.query(a, b)))<< '\n';
        }
    }

	return 0;
}
