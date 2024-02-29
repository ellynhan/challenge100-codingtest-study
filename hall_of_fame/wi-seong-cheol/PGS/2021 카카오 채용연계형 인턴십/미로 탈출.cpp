//
//  미로 탈출.cpp
//  main
//
//  Created by wi_seong on 2/19/24.
//

// 시간복잡도: O(ElogE)
// 최악시간: 1,000,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/81304

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <tuple>
#include <unordered_map>

using namespace std;
const int INF = 1e9 + 7;
#define Node tuple<int, int, int>
vector<pair<int, int>> adj[1001];
unordered_map<int, int> traps_map;
int dist[1001][1025];

bool node_is_trap(int node, int bitmask) {
    auto it = traps_map.find(node);
    if(it == traps_map.end()) {
        return false;
    }
    return (1 << it->second) & bitmask;
}

int dijkstra(int start, int end) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    pq.push({dist[start][0], start, 0});

    while (!pq.empty()) {
        auto [curDist, curNode, curBitmask] = pq.top(); pq.pop();
        if(curNode == end) {
            return dist[curNode][curBitmask];
        }
        for(const auto& [nxtNode, nxtDistRaw]: adj[curNode]) {
            int nxtDist = (node_is_trap(curNode, curBitmask) == node_is_trap(nxtNode, curBitmask)) ? nxtDistRaw : nxtDistRaw * (-1);
            int nxtBitmask = curBitmask;
            if(traps_map.find(nxtNode) != traps_map.end()) {
                nxtBitmask ^= (1 << traps_map[nxtNode]);
            }
            if(nxtDist <= 0 || dist[nxtNode][nxtBitmask] <= curDist + nxtDist) continue;
            dist[nxtNode][nxtBitmask] = curDist + nxtDist;
            pq.push({curDist + nxtDist, nxtNode, nxtBitmask});
        }
    }

    return dist[end][0];
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;

    memset(dist, INF, sizeof(dist));
    dist[start][0] = 0;

    for(auto road: roads) {
        adj[road[0]].push_back({road[1], road[2]});
        adj[road[1]].push_back({road[0], -road[2]});
    }

    for(int i = 0; i < int(traps.size()); i++) {
        traps_map[traps[i]] = i;
    }

    answer = dijkstra(start, end);

    return answer;
}
