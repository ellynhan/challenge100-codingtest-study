//
//  전력망을 둘로 나누기.cpp
//  main
//
//  Created by wi_seong on 2/14/24.
//

// 시간복잡도: O(n ^ 3)
// 최악시간: 1,000,000
// 난이도: Level 2
// Timer: 10m
// Url: https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
#include <climits>
#include <cstring>

using namespace std;
vector<int> adj[101];
bool vis[101];

int dfs(int cur, const vector<int>& wire) {
    vis[cur] = true;
    int ret = 1;

    for(int nxt: adj[cur]) {
        if(cur == wire[0] && nxt == wire[1]) continue;
        if(cur == wire[1] && nxt == wire[0]) continue;
        if(vis[nxt]) continue;
        ret += dfs(nxt, wire);
    }

    return ret;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = INT_MAX;

    for(auto wire: wires) {
        adj[wire[0]].push_back(wire[1]);
        adj[wire[1]].push_back(wire[0]);
    }

    for(auto wire: wires) {
        memset(vis, false, sizeof(vis));
        int a, b;
        a = dfs(1, wire);
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            b = dfs(i, wire);
        }
        answer = min(answer, abs(a - b));
    }

    return answer;
}
