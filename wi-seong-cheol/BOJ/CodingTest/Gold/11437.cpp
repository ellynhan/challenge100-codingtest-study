//
//  11437.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 15
 1 2
 1 3
 2 4
 3 7
 6 2
 3 8
 4 9
 2 5
 5 11
 7 13
 10 4
 11 15
 12 5
 14 7
 6
 6 11
 10 9
 2 6
 7 6
 8 13
 8 15
 [Output]
 2
 4
 2
 1
 3
 1
 */
// 시간복잡도: O(E + V)
// 최악시간: 100,000
// 난이도: Gold 3
// Timer: 50m
// Url: https://www.acmicpc.net/problem/11437

#include <iostream>
#include <vector>

using namespace std;
const int MAX = 50001;
int n, m, u, v;
vector<int> adj[MAX];
bool vis[MAX];
int depth[MAX];
int parent[MAX];

void dfs(int cur, int dpt) {
    depth[cur] = dpt;
    vis[cur] = true;
    
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        parent[nxt] = cur;
        dfs(nxt, dpt + 1);
    }
}

int lca(int a, int b) {
    while(depth[a] != depth[b]) {
        if(depth[a] > depth[b]) {
            a = parent[a];
        } else {
            b = parent[b];
        }
    }
    
    while(a != b) {
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1, 0);
    
    cin >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        cout << lca(u, v) << '\n';
    }
    
    return 0;
}
