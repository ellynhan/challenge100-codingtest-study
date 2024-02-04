//
//  부대복귀.cpp
//  main
//
//  Created by wi_seong on 1/31/24.
//

// 시간복잡도: O(k * (n + m)
// 최악시간: 300,000,000
// 난이도: Level 3
// Timer: 30m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/132266

#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <iostream>

using namespace std;
int dest;
vector<int> adj[100001];
int vis[100001];

int bfs(int st) {
    memset(vis, -1, sizeof(vis));
    queue<pair<int, int>> Q;
    Q.push({st, 0});
    vis[st] = 1;

    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        int u = cur.first;
        int dist = cur.second;
        if(u == dest) return dist;
        for(int nxt: adj[u]) {
            if(vis[nxt] != -1) continue;
            vis[nxt] = 1;
            Q.push({nxt, dist + 1});
        }
    }

    return -1;
}

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    dest = destination;

    for(auto road: roads) {
        int u = road[0];
        int v = road[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int source: sources) {
        answer.push_back(bfs(source));
    }

    return answer;
}
