//
//  NTHLON.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 3
 5
 1 2
 3 4
 5 6
 7 8
 7 3
 3
 1 100
 21 20
 10 1
 3
 10 81
 63 71
 16 51
 [Output]
 11
 111
 IMPOSSIBLE
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 160,000
// 난이도: 상
// Timer: 30m
// Url: https://algospot.com/judge/problem/read/NTHLON

#include <iostream>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;
const int MXN = 402;
const int START = 401;
int t, n, u, v;
vector<int> a, b;
vector<pair<int, int>> adj[MXN];

void init() {
    a.resize(n);
    b.resize(n);
    for(int i = 0; i < MXN; i++) {
        adj[i].clear();
    }
}

int vertex(int delta) {
    return delta + 200;
}

vector<int> dijkstra(int src) {
    vector<int> dist(MXN, numeric_limits<int>::max());
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
    return dist;
}

int solve(const vector<int>& a, const vector<int>& b) {
    int n = int(a.size());
    for(int i = 0; i < n; i++) {
        int delta = a[i] - b[i];
        adj[START].push_back({vertex(delta), a[i]});
    }
    for(int delta = -200; delta <= 200; delta++) {
        for(int i = 0; i < n; i++) {
            int next = delta + a[i] - b[i];
            if(abs(next) > 200) continue;
            adj[vertex(delta)].push_back({vertex(next), a[i]});
        }
    }

    vector<int> shortest = dijkstra(START);
    int ret = shortest[vertex(0)];
    if(ret == numeric_limits<int>::max()) {
        return -1;
    }
    return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        init();
        for(int i = 0; i < n; i++)
            cin >> a[i] >> b[i];
        int ret = solve(a, b);

        if(ret == -1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ret << '\n';
        }
    }

	return 0;
}
