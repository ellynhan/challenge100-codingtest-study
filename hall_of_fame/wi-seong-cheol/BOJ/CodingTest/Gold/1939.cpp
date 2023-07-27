//
//  1939.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 3 3
 1 2 2
 3 1 3
 2 3 2
 1 3
 [Output]
 3
 */
// 시간복잡도: O(nlog(n * m))
// 최악시간: 100,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1939

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
#define X first
#define Y second
int n, m, u, v, cost, st, en;
int high, low, maxCost;
vector<pair<int, int>> adj[10001];
bool vis[10001];

bool bfs(int cost) {
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if(cur == en) return true;
        for(auto node: adj[cur]) {
            int nxt = node.X;
            int nxtCost = node.Y;
            if(vis[nxt] || cost > nxtCost) continue;
            vis[nxt] = true;
            Q.push(nxt);
        }
    }
    
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
        maxCost = max(maxCost, cost);
    }
    cin >> st >> en;
    int low = 0;
    int high = maxCost;
    while(low <= high) {
        memset(vis, false, sizeof(vis));
        int mid = (low + high) / 2;
        if(bfs(mid)) low = mid + 1;
        else high = mid - 1;
    }
    cout << high;
    
    return 0;
}
