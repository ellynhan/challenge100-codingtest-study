//
//  트리 트리오 중간값.cpp
//  main
//
//  Created by wi_seong on 2/6/24.
//

// 시간복잡도: O(n)
// 최악시간: 750,000
// 난이도: Level 4
// Timer: 1h
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/68937#

#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
const int MXN = 250001;
vector<int> adj[MXN];
int dist[MXN];

void bfs(int start) {
    memset(dist, -1, sizeof(dist));
    dist[start] = 0;
    queue<int> Q;
    Q.push(start);

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();

        for(int nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    for(auto edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    int start = 1, cnt = 0;
    bfs(start);
    for(int i = 2; i <= n; i++)
        if(dist[i] > dist[start]) start = i;

    cnt = 0;
    bfs(start);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[start]) start = i;
    for(int i = 1; i <= n; i++)
        if(dist[start] == dist[i]) cnt++;

    if(cnt >= 2) return dist[start];

    cnt = 0;
    bfs(start);
    for(int i = 1; i <= n; i++)
        if(dist[i] > dist[start]) start = i;
    for(int i = 1; i <= n; i++)
        if(dist[start] == dist[i]) cnt++;

    if(cnt >= 2) return dist[start];
    return dist[start] - 1;
}
