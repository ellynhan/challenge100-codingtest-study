//
//  1162.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 4 1
 1 2 10
 2 4 10
 1 3 1
 3 4 100
 [Output]
 1
 */
// 시간복잡도: O(ElogE)
// 최악시간: 100,000
// 난이도: Gold 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1162

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, m, k, u, v;
ll w;
ll d[22][10002];
vector<tuple<ll, int, int>> adj[10002];
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> pq;

void solve() {
    pq.push({0, 0, 1});
    while(!pq.empty()) {
        auto [cc, ck, cur] = pq.top(); pq.pop();
        if(d[ck][cur] != cc) continue;
        for(auto [dc, dk, nxt]: adj[cur]) {
            dc += cc;
            dk += ck;
            if(dc >= d[dk][nxt]) continue;
            if(dk > k) continue;
            d[dk][nxt] = dc;
            pq.push({dc, dk, nxt});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, 0x3f, sizeof(d));
    for(int i = 0; i <= k; i++)
        d[i][1] = 0;
    
    cin >> n >> m >> k;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({w, 0, v});
        adj[v].push_back({w, 0, u});
        adj[u].push_back({0, 1, v});
        adj[v].push_back({0, 1, u});
    }
    solve();
    ll ans = 0x3f3f3f3f3f3f3f;
    for(int i = 0; i <= k; i++)
        ans = min(ans, d[i][n]);
    cout << ans;
    
    return 0;
}
