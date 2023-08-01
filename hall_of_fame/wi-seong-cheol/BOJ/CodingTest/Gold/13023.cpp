//
//  13023.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 5 5
 0 1
 1 2
 2 3
 3 0
 1 4
 [Output]
 1
 */
// 시간복잡도: O((V + E) * n)
// 최악시간: 8,000,000
// 난이도: Gold 5
// Timer: 20m
// Url: https://www.acmicpc.net/problem/13023

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, u, v;
vector<int> adj[2001];
bool vis[2001];

bool dfs(int cur, int depth) {
    if(depth == 4) return true;
    vis[cur] = true;
    bool ret = false;
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        if(dfs(nxt, depth + 1)) {
            ret = true;
            break;
        }
    }
    vis[cur] = false;
    return ret;
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
    for(int i = 0; i < n; i++) {
        if(dfs(i, 0)) {
            cout << 1;
            return 0;
        }
    }
    cout << 0;
    
    return 0;
}
