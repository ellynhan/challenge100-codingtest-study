//
//  1167.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 1 3 2 -1
 2 4 4 -1
 3 1 2 4 3 -1
 4 2 4 3 3 5 6 -1
 5 4 6 -1
 [Output]
 11
 */
// 시간복잡도: O(n + m)
// 최악시간: 200,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1167

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MX = 100'001;
int n, u, v, w, mxCost, mxNode;
bool vis[MX];
vector<pair<int, int>> adj[MX];

void dfs(int cur, int cost) {
    if(mxCost < cost) {
        mxNode = cur;
        mxCost = cost;
    }
    for(auto [nxtCost, nxt]: adj[cur]) {
        if(vis[nxt]) continue;
        vis[nxt] = true;
        dfs(nxt, cost + nxtCost);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> u;
        while(1) {
            cin >> v;
            if(v == -1) break;
            cin >> w;
            adj[u].push_back({w, v});
        }
    }
    vis[1] = true;
    dfs(1, 0);
    
    fill(vis, vis + MX, false);
    
    vis[mxNode] = true;
    dfs(mxNode, 0);
    
    cout << mxCost;
    
    return 0;
}
