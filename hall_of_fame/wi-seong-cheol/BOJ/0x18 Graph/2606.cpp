//
//  2606.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 6
 1 2
 2 3
 1 5
 5 2
 5 6
 4 7
 [Output]
 4
 */
// 시간복잡도: O(n * m)
// 최악시간: 100 * m
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/2606

#include <iostream>
#include <vector>

using namespace std;
int n, m, ans;
vector<int> adj[101];
bool vis[101];

void dfs(int cur) {
    vis[cur] = true;
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
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 2; i <= n; i++)
        ans += vis[i];
    cout << ans;
    
    return 0;
}
