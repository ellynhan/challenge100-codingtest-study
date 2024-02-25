//
//  1800.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 12/29/23.
//

/*
 [Input]
 5 7 1
 1 2 5
 3 1 4
 2 4 8
 3 2 3
 5 2 9
 3 4 7
 4 5 6
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1800

#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m, k;
vector<pair<int, int>> adj[1001];
int dist[1001];

bool dijkstra(int start, int end, int x) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        int cost = -cur.X;
        int idx = cur.Y;
        if(dist[idx] < cost) continue;
        for(auto [nxtCost, nxtIdx]: adj[idx]) {
            int w = cost + (nxtCost > x);
            if(dist[nxtIdx] <= w) continue;
            dist[nxtIdx] = w;
            pq.push({-dist[nxtIdx], nxtIdx});
        }
    }

    return dist[end] <= k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> n >> m >> k;
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    int ans = -1;
    int lo = 0, hi = 1000000;
    while(lo <= hi) {
        int mid = (lo + hi + 1) / 2;
        fill(dist, dist + 1001, INF);

        if(dijkstra(1, n, mid)) {
            hi = mid - 1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << ans;

	return 0;
}
