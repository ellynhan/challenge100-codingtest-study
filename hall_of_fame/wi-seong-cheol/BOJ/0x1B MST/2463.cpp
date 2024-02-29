//
//  2463.cpp
//  main
//
//  Created by wi_seong on 2/23/24.
//

/*
 [Input]
 6 7
 1 2 10
 2 3 2
 4 3 5
 6 3 15
 3 5 4
 4 5 3
 2 6 6
 [Output]
 256
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2463

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
const int MOD = 1e9;
ll total, result;
int n, m;
vector<pair<int, pair<int, int>>> edges;
int parent[100001], setSize[100001];

int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    parent[u] = v;
    setSize[v] += setSize[u];
    setSize[u] = 1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        parent[i] = i;
        setSize[i] = 1;
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({-w, {u, v}});
        total += w;
    }
    sort(edges.begin(), edges.end());
    for(auto edge : edges) {
        int w = -edge.first;
        int u = find(edge.second.first);
        int v = find(edge.second.second);
        if(u != v) {
            result += (((1LL * setSize[u] * setSize[v]) % MOD) * total) % MOD;
            result %= MOD;
            merge(u, v);
        }
        total -= w;
    }
    cout << result;

	return 0;
}
