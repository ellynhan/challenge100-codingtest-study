//
//  14438.cpp
//  main
//
//  Created by wi_seong on 1/29/24.
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
 2
 2
 3
 */
// 시간복잡도: O(nlogn)
// 최악시간: 600,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14438

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
    int update(int index, int newValue, int node, int nodeLeft, int nodeRight) {
        if(index < nodeLeft || nodeRight < index) return rangeMin[node];
        if(nodeLeft == nodeRight) return rangeMin[node] = newValue;
        int mid = (nodeLeft + nodeRight) / 2;
        return rangeMin[node] = min(update(index, newValue, node * 2, nodeLeft, mid), update(index, newValue, node * 2 + 1, mid + 1, nodeRight));
    }
    int update(int index, int newValue) {
        return update(index, newValue, 1, 0, n - 1);
    }
};
int n, m, op, a, b;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    RMQ rmq(v);
    cin >> m;
    while(m--) {
        cin >> op >> a >> b;
        if(op == 1) {
            rmq.update(a - 1, b);
        } else {
            cout << rmq.query(a - 1, b - 1) << '\n';
        }
    }

	return 0;
}
