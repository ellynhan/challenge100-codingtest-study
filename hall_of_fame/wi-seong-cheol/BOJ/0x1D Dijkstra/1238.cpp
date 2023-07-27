//
//  1238.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 8 2
 1 2 4
 1 3 2
 1 4 7
 2 1 1
 2 3 5
 3 1 2
 3 4 4
 4 2 3
 [Output]
 10
 */
// 시간복잡도: O(ElogE * N)
// 최악시간: 50,000,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1238

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
const int INF = 1e9 + 10;
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int n, m, st, en;
int u, v, w;
int d[1001];

int solve(int st, int en) {
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
    
    cin >> n >> m >> en;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
    }
    int ans = 0;
    for(int st = 1; st <= n; st++)
        ans = max(ans, solve(st, en) + solve(en, st));
    cout << ans;
    
    return 0;
}
