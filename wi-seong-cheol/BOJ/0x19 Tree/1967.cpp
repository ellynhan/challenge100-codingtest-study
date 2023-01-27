//
//  1967.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 12
 1 2 3
 1 3 2
 2 4 5
 3 5 11
 3 6 9
 4 7 1
 4 8 7
 5 9 15
 5 10 4
 6 11 6
 6 12 10
 [Output]
 45
 */
// 시간복잡도: O(n + m)
// 최악시간: 20,000
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1967

#include <iostream>
#include <vector>

using namespace std;
int n, u, v, w, maxNode, maxCost;
vector<pair<int, int>> adj[10001];
bool vis[10001];

void dfs(int cur, int cost) {
    if(maxCost < cost) {
        maxNode = cur;
        maxCost = cost;
    }
    for(auto [nxtCost, nxtNode]: adj[cur]) {
        if(vis[nxtNode]) continue;
        vis[nxtNode] = true;
        dfs(nxtNode, cost + nxtCost);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }
    vis[1] = true;
    dfs(1, 0);
    fill(vis, vis + n + 1, false);
    vis[maxNode] = true;
    dfs(maxNode, 0);
    cout << maxCost;
    
    return 0;
}
