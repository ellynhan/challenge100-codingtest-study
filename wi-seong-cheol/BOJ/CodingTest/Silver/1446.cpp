//
//  1446.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/08.
//

/*
 [Input]
 8 900
 0 10 9
 20 60 45
 80 190 100
 50 70 15
 160 180 14
 140 160 14
 420 901 5
 450 900 0
 [Output]
 432
 */
// 시간복잡도: O(ElogE)
// 최악시간: 50,000
// 난이도: Silver 1
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1446

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
#define X first
#define Y second
#define pii pair<int, int>
const int INF = 0x3f3f3f3f;
int N, D, u, v, w;
int d[10001];
vector<pii> adj[10001];
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra(int st) {
    d[st] = 0;
    pq.push({d[st], st});

    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        if(cur.X != d[cur.Y]) continue;
        for(auto nxt : adj[cur.Y]) {
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> D;

    memset(d, INF, sizeof(d));
    for(int i = 0; i < D; i++)
        adj[i].push_back({1, i + 1});

    for (int i = 0; i < N; i++) {
        cin >> u >> v >> w;
        if(v > D) continue;
        adj[u].push_back({w, v});
    }
    dijkstra(0);
    cout << d[D];

    return 0;
}
