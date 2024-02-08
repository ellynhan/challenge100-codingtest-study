//
//  가장 먼 노드.cpp
//  main
//
//  Created by wi_seong on 1/30/24.
//

// 시간복잡도: O(nlogn)
// 최악시간: 100,000
// 난이도: Level 3
// Timer: 15m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/49189

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
vector<int> adj[20001];
vector<int> d;
int dist[20001];

void bfs() {
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;

    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        d.push_back(dist[cur]);

        for(int nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;

    memset(dist, -1, sizeof(dist));

    for(vector<int> edge: edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    bfs();
    sort(d.begin(), d.end());
    int mx = *max_element(d.begin(), d.end());
    answer = upper_bound(d.begin(), d.end(), mx) - lower_bound(d.begin(), d.end(), mx);

    return answer;
}
