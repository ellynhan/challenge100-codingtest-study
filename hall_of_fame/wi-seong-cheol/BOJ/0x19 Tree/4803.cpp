//
//  4803.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 3
 1 2
 2 3
 3 4
 6 5
 1 2
 2 3
 3 4
 4 5
 5 6
 6 6
 1 2
 2 3
 1 3
 4 5
 5 6
 6 4
 0 0
 [Output]
 Case 1: A forest of 3 trees.
 Case 2: There is one tree.
 Case 3: No trees.
 */
// 시간복잡도: O(nlogn)
// 최악시간: 3,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/4803

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MX = 501;
int n, m, u, v;
bool vis[MX], isTree;
vector<int> adj[MX];

void dfs(int cur, int prev) {
    vis[cur] = true;
    for(int nxt: adj[cur]) {
        if(nxt == prev) continue;
        if(vis[nxt]) {
            isTree = false;
            continue;
        }
        dfs(nxt, cur);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for(int i = 1; ; i++) {
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        
        fill(vis + 1, vis + n + 1, false);
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        while(m--) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(vis[i]) continue;
            isTree = true;
            dfs(i, -1);
            cnt += isTree;
        }
        
        cout << "Case " << i << ": ";
        if(cnt == 0) {
            cout << "No trees.\n";
        } else if(cnt == 1) {
            cout << "There is one tree.\n";
        } else {
            cout << "A forest of " << cnt << " trees.\n";
        }
    }
    
    return 0;
}
