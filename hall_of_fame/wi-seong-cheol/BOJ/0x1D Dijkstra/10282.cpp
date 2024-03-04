//
//  10282.cpp
//  main
//
//  Created by wi_seong on 2/23/24.
//

/*
 [Input]
 2
 3 2 2
 2 1 5
 3 2 5
 3 3 1
 2 1 2
 3 1 8
 3 2 4
 [Output]
 2 5
 3 6
 */
// 시간복잡도: O(nlogn)
// 최악시간: 40,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10282

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define pii pair<int, int>
const int INF = 0x3f3f3f3f;
int t, n, d, c, a, b, s;
vector<pair<int, int>> adj[10001];
int dist[10001];

pii dijkstra(int st) {
    priority_queue<pii> pq;
    dist[st] = 0;
    pq.push({dist[st], st});

    while(!pq.empty()) {
        int cost = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();

        for(auto [next, nextDist]: adj[cur]) {
            if(dist[next] <= nextDist + cost) continue;
            dist[next] = nextDist + cost;
            pq.push({-dist[next], next});
        }
    }

    int cnt = 0, maxDist = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) continue;
        cnt++;
        maxDist = max(maxDist, dist[i]);
    }

    return {cnt, maxDist};
}

void init() {
    for(int i = 0; i < 10001; i++) {
        adj[i].clear();
    }
    memset(dist, INF, sizeof(dist));
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        init();
        cin >> n >> d >> c;
        for(int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            adj[b].push_back({a, s});
        }
        pii result = dijkstra(c);
        cout << result.first << " " << result.second << "\n";
    }

	return 0;
}
