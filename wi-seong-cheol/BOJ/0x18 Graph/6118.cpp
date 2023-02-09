//
//  6118.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 7
 3 6
 4 3
 3 2
 1 3
 1 2
 2 4
 5 2
 [Output]
 4 2 3
 */
// 시간복잡도: O(n + m)
// 최악시간: 70,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/6118

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v;
vector<int> adj[20001];
int dist[20001];

void bfs() {
    queue<int> Q;
    Q.push(1);
    dist[1] = 0;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    fill(dist, dist + n + 1, -1);
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs();
    int mx = *max_element(dist + 1, dist + n + 1);
    int idx = 0;
    int cnt = 0;
    for(int i = 2; i <= n; i++) {
        if(dist[i] != mx) continue;
        if(!idx) idx = i;
        cnt++;
    }
    cout << idx << ' ' << mx << ' ' << cnt;
    
    return 0;
}
