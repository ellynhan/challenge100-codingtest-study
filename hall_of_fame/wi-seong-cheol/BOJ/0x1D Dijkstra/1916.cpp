//
//  1916.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 8
 1 2 2
 1 3 3
 1 4 1
 1 5 10
 2 4 2
 3 4 1
 3 5 1
 4 5 3
 1 5
 [Output]
 4
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1916

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
const int INF = 1e9 + 10;
int n, m, st, en;
int u, v, w;
int d[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int solve() {
    fill(d, d + n + 1, INF);
    d[st] = 0;
    pq.push({d[st], st});
    
    while(!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    
    return d[en];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    cin >> st >> en;
    cout << solve();
    
    return 0;
}
