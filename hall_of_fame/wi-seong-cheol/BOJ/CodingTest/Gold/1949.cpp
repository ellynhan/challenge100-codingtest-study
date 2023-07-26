//
//  1949.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 7
 1000 3000 4000 1000 2000 2000 7000
 1 2
 2 3
 4 3
 4 5
 6 2
 6 7
 [Output]
 14000
 */
// 시간복잡도: O(V + E)
// 최악시간: 10,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1949

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, u, v, ans;
int a[10001];
int d[10001][2];    // 0: 우수마을 아닐 때, 1: 우수마을 일 때
bool vis[10001];
vector<int> adj[10001];

void dfs(int cur) {
    if(vis[cur]) return;
    
    vis[cur] = true;
    d[cur][0] = 0;
    d[cur][1] = a[cur];
    
    for(int nxt: adj[cur]) {
        if(vis[nxt]) continue;
        dfs(nxt);
        d[cur][0] += max(d[nxt][0], d[nxt][1]);
        d[cur][1] += d[nxt][0];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    cout << max(d[1][0], d[1][1]);
    
    return 0;
}
