//
//  TIMETRIP.cpp
//  main
//
//  Created by wi_seong on 1/27/24.
//

/*
 [Input]
 4
 2 2
 0 1 1
 0 1 3
 4 4
 0 2 -7
 0 3 -4
 3 2 9
 2 1 3
 4 3
 0 2 0
 2 2 1
 2 1 0
 3 0
 [Output]
 1 3
 -4 8
 0 INFINITY
 UNREACHABLE
 */
// 시간복잡도: O(V * E)
// 최악시간: 10,000
// 난이도: 중
// Timer: 1h
// Url: https://algospot.com/judge/problem/read/TIMETRIP

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MXN = 101;
const int INF = 987654321;
int t, V, W, u, v, w;
vector<pair<int, int>> adjMax[MXN], adjMin[MXN];
bool reachable[MXN][MXN];

void init() {
    memset(reachable, false, sizeof(reachable));
    for(int i = 0; i < 100; i++) {
        adjMax[i].clear();
        adjMin[i].clear();
    }
}

void calcReachable() {
    for(int i = 0; i < V; i++)
        reachable[i][i] = true;
    for(int k = 0; k < V; k++)
        for(int i = 0; i < V; i++)
            for(int j = 0; j < V; j++)
                reachable[i][j] = reachable[i][j] || (reachable[i][k] && reachable[k][j]);
}

int bellman(int src, int target, const vector<pair<int, int>>* adj) {
    vector<int> upper(V, INF);
    upper[src] = 0;

    for(int iter = 0; iter < V - 1; iter++)
        for(int here = 0; here < V; here++)
            for(int i = 0; i < adj[here].size(); i++) {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;
                upper[there] = min(upper[there], upper[here] + cost);
            }

    for(int here = 0; here < V; here++)
        for (int i = 0; i < adj[here].size(); i++) {
            int there = adj[here][i].first;
            int cost = adj[here][i].second;
            if(upper[here] + cost < upper[there])
                if(reachable[src][here] && reachable[here][target])
                    return -INF;
        }
    return upper[target];
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> V >> W;
        init();
        for (int i = 0; i < W; i++) {
            cin >> u >> v >> w;
            adjMin[u].push_back(make_pair(v, w));
            adjMax[u].push_back(make_pair(v, -w));
            reachable[u][v] = true;
        }
        calcReachable();
        int minimum = bellman(0, 1, adjMin);
        int maximum = bellman(0, 1, adjMax);

        if(!reachable[0][1]) {
            cout << "UNREACHABLE" << '\n';
        } else {
            if(minimum == -INF)
                cout << "INFINITY" << ' ';
            else
                cout << minimum << ' ';
            if(maximum == -INF)
                cout << "INFINITY" << '\n';
            else
                cout << -maximum << '\n';
        }
    }

	return 0;
}
