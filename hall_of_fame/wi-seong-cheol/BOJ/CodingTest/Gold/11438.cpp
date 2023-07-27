//
//  11438.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/23.
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
// 시간복잡도: O(N + M * log N)
// 최악시간: 100,085
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/11438

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
const int MAX = 100'001;
const int MAX_LOG = 17;
int N, M;
vector<int> adj[MAX];
int depth[MAX];
int parent[MAX][MAX_LOG];

void dfs(int cur, int prev) {
    depth[cur] = depth[prev] + 1;
    parent[cur][0] = prev;

    for(int i = 1; i < MAX_LOG; i++) {
        int prev_parent = parent[cur][i - 1];
        parent[cur][i] = parent[prev_parent][i - 1];
    }

    for(int nxt : adj[cur]) {
        if(nxt != prev) dfs(nxt, cur);
    }
}

int LCA(int u, int v) {
    if(depth[u] < depth[v]) swap(u, v);

    int diff = depth[u] - depth[v];
    for(int i = 0; diff; i++, diff /= 2) {
        if(diff % 2) u = parent[u][i];
    }

    if(u == v) return u;

    for(int i = MAX_LOG-1; i >= 0; i--) {
        if(parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    int u, v;
    for (int i = 1; i < N; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, 0);

    cin >> M;
    while(M--) {
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }

    return 0;
}
