//
//  17835.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 10 2
 2 6 2
 1 4 1
 6 1 5
 2 5 1
 5 1 4
 4 5 6
 6 2 3
 3 5 1
 3 1 1
 5 2 2
 1 2
 [Output]
 4
 8
 */
// 시간복잡도: O(VElogE)
// 최악시간: 800,000,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17835

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define ll long long
#define INF 0x7f7f7f7f7f7f
#define X first
#define Y second
#define pli pair<ll, int>
#define MX 100001
int n, m, k, u, v, ct;
ll w;
ll d[MX];
vector<pli> adj[MX];
priority_queue<pli, vector<pli>, greater<pli>> pq;

void dijkstra() {
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
    
    cin >> n >> m >> k;
    fill(d + 1, d + n + 1, INF);
    while(m--) {
        cin >> u >> v >> w;
        adj[v].push_back({w, u});
    }
    while(k--) {
        cin >> ct;
        d[ct] = 0;
        pq.push({d[ct], ct});
    }
    
    dijkstra();

    long cidx = max_element(d + 1, d + n + 1) - d;
    cout << cidx << '\n' << d[cidx];
    
    return 0;
}
