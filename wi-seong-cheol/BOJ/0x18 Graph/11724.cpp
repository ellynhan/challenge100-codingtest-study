//
//  11724.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 5
 1 2
 2 5
 5 1
 3 4
 4 6
 [Output]
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 500,000,000
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11724

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v;
bool vis[1001];
vector<int> adj[1001];

void bfs(int x) {
    queue<int> Q;
    Q.push(x);
    vis[x] = true;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(auto nxt : adj[cur]) {
            if(vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
        }
    }
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
    
    int num = 0;
    for(int i = 1; i <= n; i++) {
        if(vis[i]) continue;
        num++;
        bfs(i);
    }
    cout << num;
    
    return 0;
}
