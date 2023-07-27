//
//  1260.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 5 3
 5 4
 5 2
 1 2
 3 4
 3 1
 [Output]
 3 1 2 5 4
 3 1 4 2 5
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1260

#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
int n, m, st;
vector<int> adj[1001];
bool vis[1001];

// 재귀
void dfs1(int cur) {
    vis[cur] = true;
    cout << cur << ' ';
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        dfs1(nxt);
    }
}

// 비재귀
void dfs2() {
    stack<int> S;
    S.push(st);
    while(!S.empty()) {
        int cur = S.top(); S.pop();
        if(vis[cur]) continue;
        vis[cur] = true;
        cout << cur << ' ';
        for(int i = 0; i < adj[cur].size(); i++) {
            int nxt = adj[cur][adj[cur].size() - 1 - i];
            if(vis[nxt]) continue;
            S.push(nxt);
        }
    }
}

void bfs() {
    queue<int> Q;
    Q.push(st);
    vis[st] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for(int nxt: adj[cur]) {
            if(vis[nxt]) continue;
            vis[nxt] = true;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> st;
    for(int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++)
        sort(adj[i].begin(), adj[i].end());
    dfs1(st);
//    dfs2();
    cout << '\n';
    fill(vis + 1, vis + n + 1, false);
    bfs();
    
    return 0;
}
