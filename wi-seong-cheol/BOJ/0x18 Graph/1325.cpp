//
//  1325.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 4
 3 1
 3 2
 4 3
 5 3
 [Output]
 1 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1325

#include <iostream>
#include <vector>

using namespace std;
int n, m, mx;
vector<int> adj[10001];
int sc[10001];
bool vis[10001];

void dfs(int cur) {
    vis[cur] = true;
    sc[cur]++;
    mx = max(mx, sc[cur]);
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
    }
    for(int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        dfs(i);
    }
    for(int i = 1; i <= n; i++)
        if(mx == sc[i])
            cout << i << ' ';
    
    return 0;
}
