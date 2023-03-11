//
//  20955.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 2
 1 2
 3 4
 [Output]
 1
 */
// 시간복잡도: O(n + e)
// 최악시간: 200,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/20955

#include <iostream>
#include <vector>

using namespace std;
const int MX = 100'001;
int n, m, u, v, cnt;
bool vis[MX];
vector<int> adj[MX];

void dfs(int cur) {
    if(vis[cur]) return;
    vis[cur] = true;
    for(int nxt: adj[cur])
        dfs(nxt);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        dfs(i);
        cnt++;
    }
    cout << (cnt - 1) + (m + cnt - 1) - (n - 1);
    
    return 0;
}
