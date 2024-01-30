//
//  섬 연결하기.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(n ^ 2)
// 최악시간: 10,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/42861

#include <string>
#include <vector>
#include <iostream>

using namespace std;
const int INF = 1e9 + 7;
const int MXN = 101;
int V;
vector<pair<int, int>> adj[MXN];

int prim() {
    int ret = 0;
    vector<bool> added(V, false);
    vector<int> minWeight(V, INF);
    minWeight[0] = 0;

    for(int i = 0; i < V; i++) {
        int u = -1;
        for(int v = 0; v < V; v++)
            if(!added[v] && (u == -1 || minWeight[u] > minWeight[v]))
                u = v;

        ret += minWeight[u];
        added[u] = true;

        for(auto nxt: adj[u]) {
            int v = nxt.first;
            int cost = nxt.second;

            if(!added[v] && minWeight[v] > cost) {
                minWeight[v] = cost;
            }
        }
    }

    return ret;
}

int solution(int n, vector<vector<int>> costs) {
    V = n;

    for(auto cost: costs) {
        adj[cost[0]].push_back({cost[1], cost[2]});
        adj[cost[1]].push_back({cost[0], cost[2]});
    }

    int answer = prim();

    return answer;
}
