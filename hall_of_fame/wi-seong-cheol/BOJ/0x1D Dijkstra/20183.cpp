//
//  20183.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 5 1 3 10
 1 2 5
 2 3 5
 1 4 1
 4 5 6
 5 3 1
 [Output]
 5
 */
// 시간복잡도: O(log(수금액) * VlogE))
// 최악시간: 5,130,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/20183

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <memory.h>

using namespace std;
#define ll long long
#define pli pair<ll, int>
const int NMX = 100'001;
const int MMX = 500'001;
int n, m, st, en, u, v;
ll lo = 1, hi, w, c;
vector<pli> adj[MMX];
priority_queue<pli, vector<pli>, greater<pli>> pq;
ll d[NMX];

bool dijkstra(ll lim) {
    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    pq.push({0, st});
    
    while(!pq.empty()) {
        auto [co, cur] = pq.top(); pq.pop();
        if(d[cur] != co) continue;
        for(auto [dist, nxt] : adj[cur]) {
            if(dist > lim) continue;
            dist += co;
            if(d[nxt] <= dist) continue;
            d[nxt] = dist;
            pq.push({dist, nxt});
        }
    }
    
    if(d[en] > c) return 0;
    return 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> st >> en >> c;
    while(m--) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
        hi = max(hi, w);
    }
    
    while(lo < hi) {
        ll mid = (lo + hi) / 2;
        if(dijkstra(mid)) hi = mid;
        else lo = mid + 1;
    }
    
    if(dijkstra(lo)) cout << lo;
    else cout << -1;
    
    return 0;
}
