//
//  FAMILYTREE.cpp
//  main
//
//  Created by wi_seong on 1/23/24.
//

/*
 [Input]
 1
 13 5
 0 1 1 3 3 0 6 0 8 9 9 8
 2 7
 10 11
 4 11
 7 7
 10 0
 [Output]
 4
 2
 6
 0
 3
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/FAMILYTREE

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

const int MXN = 100000;
int t, n, q;
vector<int> child[MXN];
int no2serial[MXN], serial2no[MXN];
int locInTrip[MXN], depth[MXN];
int nextSerial;

void traverse(int here, int d, vector<int>& trip) {
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    nextSerial++;
    depth[here] = d;
    locInTrip[here] = int(trip.size());
    trip.push_back(no2serial[here]);

    for(int i = 0; i < int(child[here].size()); i++) {
        traverse(child[here][i], d + 1, trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* prepareRMQ() {
    nextSerial = 0;
    vector<int> trip;
    traverse(0, 0, trip);
    return new RMQ(trip);
}

int distance(RMQ* rmq, int u, int v) {
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu, lv);
    int lca = serial2no[rmq->query(lu, lv)];
    return depth[u] + depth[v] - 2 * depth[lca];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> q;
        for(int i = 0; i < n; i++) {
            child[i].clear();
        }
        for(int i = 1; i < n; i++) {
            int parent; cin >> parent;
            child[parent].push_back(i);
        }
        RMQ* rmq = prepareRMQ();
        for(int i = 0; i < q; i++) {
            int u, v; cin >> u >> v;
            cout << distance(rmq, u, v) << '\n';
        }
    }

	return 0;
}
