//
//  ROUTING.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 1
 7 14
 0 1 1.3
 0 2 1.1
 0 3 1.24
 3 4 1.17
 3 5 1.24
 3 1 2
 1 2 1.31
 1 2 1.26
 1 4 1.11
 1 5 1.37
 5 4 1.24
 4 6 1.77
 5 6 1.11
 2 6 1.2
 [Output]
 1.3200000000
 */
// 시간복잡도: O(E * Log(V))
// 최악시간: 80,000
// 난이도: 하
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/ROUTING

#include <iostream>
#include <queue>
#include <algorithm>
#include <numeric>

using namespace std;
int t, V, E;
vector<pair<int, double>> adj[10001];

vector<double> dijkstra(int src) {
    vector<double> dist(V, numeric_limits<double>::max());
    dist[src] = 1;
    priority_queue<pair<double, int>> pq;
    pq.push({-1.0, src});

    while(!pq.empty()) {
        double cost = -pq.top().first;
        int here = pq.top().second; pq.pop();

        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            double nextDist = cost * adj[here][i].second;

            if (dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }

    return dist;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.precision(10);
    cout << fixed;

    cin >> t;
    while(t--) {
        cin >> V >> E;
        for(int i = 0; i < V; i++) {
            adj[i].clear();
        }
        for(int i = 0; i < E; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            adj[v].push_back({u, w});
            adj[u].push_back({v, w});
        }
        cout << dijkstra(0)[V - 1] << "\n";
    }

	return 0;
}
