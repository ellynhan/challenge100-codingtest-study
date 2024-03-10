//
//  1185.cpp
//  main
//
//  Created by wi_seong on 2/23/24.
//

/*
 [Input]
 5 7
 10
 10
 20
 6
 30
 1 2 5
 2 3 5
 2 4 12
 3 4 17
 2 5 15
 3 5 6
 4 5 12
 [Output]
 176
 */
// 시간복잡도: O(ElogE)
// 최악시간: 40,000
// 난이도: Platinum 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1185

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MXN = 10001;
int n, m;
int minCost = 1001;
int cost[MXN];
vector<int> p(MXN, -1);
vector<pair<int, int>> adj[MXN];
vector<pair<int, pair<int, int>>> edges;

int find(int u) {
    if(p[u] < 0) return u;
    return p[u] = find(p[u]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int kruskal() {
    int min_spanning = 0;

    for(int u = 1; u <= n; u++) {
        for(auto [v, w]: adj[u]) {
            edges.push_back({w, {u, v}});
        }
    }

    sort(edges.begin(), edges.end());

    int cnt = 0;
    for(auto [w, edge]: edges) {
        int u = edge.first;
        int v = edge.second;
        if(!is_diff_group(u, v)) continue;
        min_spanning += w;
        cnt++;
        if(cnt == n - 1) break;
    }

    return min_spanning + minCost;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> cost[i];
        minCost = min(minCost, cost[i]);
    }
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        int c = w * 2 + cost[u] + cost[v];
        adj[u].push_back({v, c});
    }

    cout << kruskal();

	return 0;
}
