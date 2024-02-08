//
//  TPATH.cpp
//  main
//
//  Created by wi_seong on 1/28/24.
//

/*
 [Input]
 3
 2 1
 0 1 100
 4 3
 0 1 127
 1 2 14
 2 3 96
 4 4
 0 1 100
 1 3 99
 0 2 17
 2 3 10
 [Output]
 0
 113
 1
 */
// 시간복잡도: O(E ^ 2)
// 최악시간: 16,000,000
// 난이도: 상
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/TPATH

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 987654321;
struct DisjointSet {
    vector<int> parent, rank;
    DisjointSet(int n) : parent(n), rank(n, 1) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int u) {
        if(u == parent[u]) return u;
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v) {
        u = find(u); v = find(v);
        if(u == v) return;
        if(rank[u] > rank[v]) swap(u, v);
        parent[u] = v;
        if(rank[u] == rank[v]) rank[v]++;
    }
};
int t, V, E, u, v, w;
vector<pair<int, pair<int, int>>> edges;
vector<int> weights;

void init() {
    edges = vector<pair<int, pair<int, int>>>();
    weights.clear();
}

int kruskalMinUpperBound(int low) {
    DisjointSet sets(V);
    for(int i = 0; i < edges.size(); i++) {
        if(edges[i].first < weights[low]) continue;
        sets.merge(edges[i].second.first, edges[i].second.second);
        if(sets.find(0) == sets.find(V - 1))
            return edges[i].first;
    }
    return INF;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> V >> E;
        init();
        for(int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            edges.push_back({w, {u, v}});
        }
        sort(edges.begin(), edges.end());
        for(int i = 0; i < E; i++) {
            weights.push_back(edges[i].first);
        }
        int ret = INF;
        for(int i = 0; i < E; i++) {
            ret = min(ret, kruskalMinUpperBound(i) - weights[i]);
        }
        cout << ret << "\n";
    }

	return 0;
}
