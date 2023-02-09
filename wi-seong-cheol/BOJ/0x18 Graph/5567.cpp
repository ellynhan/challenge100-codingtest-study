//
//  5567.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6
 5
 1 2
 1 3
 3 4
 2 3
 4 5
 [Output]
 3
 */
// 시간복잡도: O(n + m)
// 최악시간: 10,500
// 난이도: Silver 2
// Timer: 10m
// Url: https://www.acmicpc.net/problem/5567

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v;
vector<int> adj[501];
int depth[501];

int bfs() {
    int cnt = 0;
    queue<int> Q;
    Q.push(1);
    depth[1] = 0;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(depth[cur] + 1 > 2 || depth[nxt] != -1) continue;
            Q.push(nxt);
            depth[nxt] = depth[cur] + 1;
            cnt++;
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(depth, depth + n + 1, -1);
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout << bfs();
    
    return 0;
}
