//
//  FIRETRUCKS.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 1
 8 12 3 2
 1 2 3
 1 6 9
 2 3 6
 3 4 4
 3 5 2
 4 5 7
 6 5 5
 8 6 5
 6 7 3
 8 7 3
 7 5 1
 2 8 3
 2 3 5
 4 6
 [Output]
 16
 */
// 시간복잡도: O(ElogV)
// 최악시간: 750,000
// 난이도: 중
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/FIRETRUCKS

#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>

using namespace std;
const int MAX_V = 1001;
int t, V, E, n, m, u, v, w;
vector<pair<int, int>> adj[MAX_V];
vector<int> fire;

int solve(int src) {
    vector<int> dist(V + 1, numeric_limits<int>::max());
    dist[src] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, src});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second; pq.pop();

        if(dist[here] < cost) continue;

        for(int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there] > nextDist) {
                dist[there] = nextDist;
                pq.push({-nextDist, there});
            }
        }
    }

    int ret = 0;
    for(int i = 0; i < fire.size(); i++) {
        ret += dist[fire[i]];
    }

    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> V >> E >> n >> m;
        for(int i = 0; i < V + 1; i++) {
            adj[i].clear();
        }
        for(int i = 0; i < E; i++) {
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        fire.clear();
        for(int i = 0; i < n; i++) {
            cin >> u;
            fire.push_back(u);
        }
        for(int i = 0; i < m; i++) {
            cin >> u;
            adj[0].push_back({u, 0});
        }

        cout << solve(0) << '\n';
    }

	return 0;
}
