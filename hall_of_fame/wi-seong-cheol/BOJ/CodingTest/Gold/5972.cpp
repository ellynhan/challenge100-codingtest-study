//
//  5972.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 6 8
 4 5 3
 2 4 0
 4 1 4
 2 1 1
 5 6 1
 3 6 2
 3 2 6
 3 4 4
 [Output]
 5
 */
// 시간복잡도: O(ElogE)
// 최악시간: 2,500,000
// 난이도: Gold 5
// Timer: 15m
// Url: https://www.acmicpc.net/problem/5972

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
#define X first
#define Y second
#define pii pair<int, int>
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
int d[50001];
vector<pair<int, int>> adj[50001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int st) {
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
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(d, d + n + 1, INF);
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    dijkstra(1);
    cout << d[n];
    
    return 0;
}
