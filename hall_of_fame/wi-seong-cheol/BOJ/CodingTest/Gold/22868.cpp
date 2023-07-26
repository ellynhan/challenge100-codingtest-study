//
//  22868.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 4 5
 1 2
 1 3
 2 3
 2 4
 3 4
 1 4
 [Output]
 4
 */
// 시간복잡도: O(v + e)
// 최악시간: 120,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/22868

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
const int SIZE = 100'001;
int n, m, u, v, s, e;
bool vis[SIZE];
int path[SIZE];
vector<int> adj[SIZE];

int bfs(int st, int en) {
    queue<pair<int, int>> Q;
    Q.push({st, 0});
    vis[st] = true;
    
    while(!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int nxt: adj[cur.X]) {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            path[nxt] = cur.X;
            Q.push({nxt, cur.Y + 1});
            if(nxt == en) return cur.Y + 1;
        }
    }
    return 0;
}

void init() {
    fill(vis, vis + n + 1, false);
    
    int cur = path[e];
    while(cur != s) {
        vis[cur] = true;
        cur = path[cur];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s >> e;
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    int ans = bfs(s, e);
    init();
    ans += bfs(e, s);
    cout << ans;
    
    return 0;
}
