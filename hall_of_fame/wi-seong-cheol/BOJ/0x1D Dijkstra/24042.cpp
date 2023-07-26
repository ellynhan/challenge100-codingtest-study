//
//  24042.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 5
 1 2
 3 4
 1 3
 4 1
 2 3
 [Output]
 4
 */
// 시간복잡도: O(nlogn)
// 최악시간: 500,000
// 난이도: Gold 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/24042

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define pli pair<ll, int>
#define X first
#define Y second
const int MAX = 100001;
const ll LNF = 1e16;
int n, m, u, v;
ll d[MAX];
vector<pli> adj[MAX];
priority_queue<pli, vector<pli>, greater<pli>> pq;

void dijkstra() {
    d[1] = 0;
    pq.push({d[1], 1});
    
    while (!pq.empty()) {
        auto [time, cur] = pq.top(); pq.pop();
        if(d[cur] < time) continue;
        for(auto nxt : adj[cur]) {
            int next = nxt.Y;
            ll nTime = nxt.X + m * (time / m);
            while(nTime <= time)
                nTime += m;
            if(d[next] <= nTime) continue;
            d[next] = nTime;
            pq.push({d[next], next});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(d, d + MAX, LNF);
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        adj[u].push_back({i, v});
        adj[v].push_back({i, u});
    }
    dijkstra();
    cout << d[n];
    
    return 0;
}
