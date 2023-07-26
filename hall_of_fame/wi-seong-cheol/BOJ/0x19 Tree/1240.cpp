//
//  1240.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 2
 2 1 2
 4 3 2
 1 4 3
 1 2
 3 2
 [Output]
 2
 7
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1240

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define X first
#define Y second
const int SIZE = 1001;
int n, m, u, v, d;
vector<pair<int, int>> adj[SIZE];
bool vis[SIZE];

void dfs(pair<int, int> cur) {
    vis[cur.X] = true;
    if (cur.X == v) {
        cout << cur.Y << '\n';
        return;;
    }
    for(auto [nxt, nxtDist] : adj[cur.X]) {
        if (vis[nxt]) continue;
        dfs({nxt, cur.Y + nxtDist});
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
        adj[v].push_back({u, d});
    }
    while (m--) {
        cin >> u >> v;
        fill(vis, vis + SIZE, false);
        dfs({u, 0});
    }
    
    return 0;
}
