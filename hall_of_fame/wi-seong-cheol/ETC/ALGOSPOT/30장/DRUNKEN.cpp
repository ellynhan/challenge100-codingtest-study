//
//  DRUNKEN.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 8 12
 8 6 5 8 3 5 8 4
 1 6 9
 1 2 3
 2 8 3
 6 8 5
 6 7 3
 8 7 3
 6 5 5
 4 5 7
 3 4 4
 3 5 2
 2 3 6
 7 5 1
 2
 1 5
 6 3
 [Output]
 17
 10
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/DRUNKEN

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 987654321;
const int MXN = 501;
int t, V, E, u, v, w;
int adj[MXN][MXN];
int W[MXN][MXN];
int delay[MXN];

void init() {
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = INF;
        }
    }
}

void solve() {
    vector<pair<int, int>> order;
    for(int i = 0; i < V; i++) {
        order.push_back({delay[i], i});
    }
    sort(order.begin(), order.end());
    for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
            if(i == j) W[i][j] = 0;
            else W[i][j] = adj[i][j];
        }
    }

    for(int k = 0; k < V; k++) {
        int w = order[k].second;
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = min(adj[i][j], adj[i][w] + adj[w][j]);
                W[i][j] = min(W[i][j], adj[i][w] + delay[w] + adj[w][j]);
            }
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> V >> E;
    init();
    for(int i = 0; i < V; i++) {
        cin >> delay[i];
    }
    for(int i = 0; i < E; i++) {
        cin >> u >> v >> w;
        u--; v--;
        adj[u][v] = adj[v][u] = w;
    }
    solve();

    cin >> t;
    while(t--) {
        cin >> u >> v;
        cout << W[--u][--v] << '\n';
    }

	return 0;
}
