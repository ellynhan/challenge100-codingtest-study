//
//  신비로운 유적 탐험.cpp
//  main
//
//  Created by wi_seong on 2/20/24.
//

// 시간복잡도: O(n ^ 4)
// 최악시간: 100,000,000
// 난이도: Level 5
// Timer: 2h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/1834

#include <cstring>
#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string>

using namespace std;
const int inf = 0x3c3c3c3c;

struct MCMF {
    struct edge {
        int to, cap, cost, rev;
    };
    int size, src, sink;
    vector<vector<edge>> G;
    vector<int> dist, par, edgeIdx;

    MCMF(int size, int src, int sink) {
        G = vector<vector<edge>>(size);
        par = vector<int>(size);
        edgeIdx = vector<int>(size);
        this->size = size;
        this->src = src;
        this->sink = sink;
    }

    bool spfa() {
        vector<bool> inQ = vector<bool>(size, false);
        queue<int> q;
        q.push(src);
        inQ[src] = true;
        dist[src] = 0;
        while (!q.empty()) {
            int here = q.front();
            q.pop();
            inQ[here] = false;
            for (int i = 0; i < (int)G[here].size(); i++) {
                auto e = G[here][i];
                if (e.cap > 0 && dist[here] + e.cost < dist[e.to]) {
                    dist[e.to] = dist[here] + e.cost;
                    par[e.to] = here;
                    edgeIdx[e.to] = i;
                    if (!inQ[e.to]) q.push(e.to), inQ[e.to] = true;
                }
            }
        }
        if (dist[sink] >= 0) return false;
        return dist[sink] != inf;
    }

    pair<int, int> getMCMF() {
        int maxFlow = 0;
        int minCost = 0;
        while (1) {
            dist = vector<int>(size, inf);
            if (!spfa()) break;
            int minFlow = inf;
            int costSum = 0;
            for (int p = sink; p != src; p = par[p]) {
                auto& e = G[par[p]][edgeIdx[p]];
                minFlow = min(minFlow, e.cap);
                costSum += e.cost;
            }
            for (int p = sink; p != src; p = par[p]) {
                auto& e = G[par[p]][edgeIdx[p]];
                e.cap -= minFlow;
                G[e.to][e.rev].cap += minFlow;
            }
            maxFlow += minFlow;
            minCost += costSum * minFlow;
        }
        return {maxFlow, minCost};
    }

    void addEdge(int from, int to, int cap, int cost) {
        G[from].push_back({to, cap, cost, (int)G[to].size()});
        G[to].push_back({from, 0, -cost, (int)G[from].size() - 1});
    }
};

vector<int> G1[103], G2[103];
int dp[103][103];

int go(int cur1, int dad1, int cur2, int dad2) {
    int& cache = dp[cur1][cur2];
    if (cache != -1) return cache;
    int N1 = G1[cur1].size();
    int N2 = G2[cur2].size();
    int src = N1 + N2, sink = src + 1;
    MCMF mcmf(2 + N1 + N2, src, sink);
    for (int i = 0; i < N1; i++) {
        int u = G1[cur1][i];
        if (u == dad1) continue;
        for (int j = 0; j < N2; j++) {
            int v = G2[cur2][j];
            if (v == dad2) continue;
            int cost = go(u, cur1, v, cur2);
            mcmf.addEdge(i, N1 + j, 1, -cost);
        }
        mcmf.addEdge(src, i, 1, 0);
    }
    for (int i = 0; i < N2; i++) {
        int u = G2[cur2][i];
        mcmf.addEdge(N1 + i, sink, 1, 0);
    }
    int ret = -mcmf.getMCMF().second + 1;
    return cache = ret;
}

int solution(int n1, vector<vector<int>> g1, int n2, vector<vector<int>> g2) {
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < 103; i++) G1[i].clear(), G2[i].clear();
    for (auto v : g1) {
        int a = v[0], b = v[1];
        G1[a].push_back(b);
        G1[b].push_back(a);
    }
    for (auto v : g2) {
        int a = v[0], b = v[1];
        G2[a].push_back(b);
        G2[b].push_back(a);
    }
    return go(1, 0, 1, 0);
}
