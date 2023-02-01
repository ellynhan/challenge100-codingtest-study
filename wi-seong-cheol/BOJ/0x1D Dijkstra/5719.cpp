//
//  5719.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7 9
 0 6
 0 1 1
 0 2 1
 0 3 2
 0 4 3
 1 5 2
 2 6 4
 3 6 2
 4 6 4
 5 6 1
 4 6
 0 2
 0 1 1
 1 2 1
 1 3 1
 3 2 1
 2 0 3
 3 0 2
 6 8
 0 1
 0 1 1
 0 2 2
 0 3 3
 2 5 3
 3 4 2
 4 1 1
 5 1 1
 3 0 1
 0 0
 [Output]
 5
 -1
 6
 */
// 시간복잡도: O(ElogE)
// 최악시간: 40,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/5719

#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;
#define pii pair<int, int>
#define MX 501
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m, st, en, u, v, w;
int d[MX];
vector<int> pre[1001];
map<int, int> adj[500];
vector<bool> vis(500);
priority_queue<pii, vector<pii>, greater<pii>> pq;

void dijkstra() {
    fill(d, d + n, INF);
    d[st] = 0;
    pq.push({d[st], st});
    while(!pq.empty()) {
        int now = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        if(d[now] != cost) continue;
        for(auto nxt: adj[now]) {
            auto [next, ncost] = nxt;
            if(ncost == -1 || d[next] < d[now] + ncost) { continue;
            } else if(d[next] > d[now] + ncost) {
                pre[next].clear();
                pre[next].push_back(now);
                d[next] = d[now] + ncost;
                pq.push({-d[next], next});
            } else {
                pre[next].push_back(now);
            }
        }
    }
}

void removePath(int now) {
    if (now == st || vis[now]) return;
    vis[now] = true;
    
    for (int i = 0; i < pre[now].size(); i++) {
        int next = pre[now][i];
        adj[next][now] = -1;
        removePath(pre[now][i]);
    }
}

void init() {
    for(int i = 0; i < n; i++) {
        adj[i].clear();
        pre[i].clear();
        vis[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cin >> st >> en;
        init();
        while(m--) {
            cin >> u >> v >> w;
            adj[u][v] = w;
        }
        dijkstra();
        removePath(en);
        dijkstra();
        
        if(d[en] == INF) cout << -1 << '\n';
        else cout << d[en] << '\n';
    }
    
    return 0;
}
