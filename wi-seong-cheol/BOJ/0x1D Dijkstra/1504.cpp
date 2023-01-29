//
//  1504.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 6
 1 2 3
 2 3 3
 3 4 1
 1 3 5
 2 4 5
 1 4 4
 2 3
 [Output]
 7
 */
// 시간복잡도: O(ElogE)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1504

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define X first
#define Y second
const int INF = 1e9 + 10;
int n, m, a, b;
int u, v, w;
vector<pair<int, int>> adj[801];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int d[801];

ll solve(int st, int en) {
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
        adj[v].push_back({w, u});
    }
    cin >> a >> b;
    ll len1 = solve(1, a) + solve(a, b) + solve(b, n);
    ll len2 = solve(1, b) + solve(b, a) + solve(a, n);
    ll len = min(len1, len2);
    if(len >= INF) cout << -1;
    else cout << len;
    
    return 0;
}
