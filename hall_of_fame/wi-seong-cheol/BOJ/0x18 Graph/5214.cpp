//
//  5214.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9 3 5
 1 2 3
 1 4 5
 3 6 7
 5 6 7
 6 8 9
 [Output]
 4
 */
// 시간복잡도: O(n + m)
// 최악시간: 101,000
// 난이도: Gold 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/5214

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, k, m;
vector<int> adj[101001];
int dist[101001];

void bfs() {
    queue<int> Q;
    Q.push(1);
    dist[1] = 1;
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(dist[nxt] != -1) continue;
            Q.push(nxt);
            dist[nxt] = dist[cur] + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k >> m;
    fill(dist, dist + n + m + 1, -1);
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= k; j++) {
            int x; cin >> x;
            adj[n + i].push_back(x);
            adj[x].push_back(n + i);
        }
    }
    bfs();
    if(dist[n] == -1) cout << dist[n];
    else cout << dist[n]/2 + 1;
    
    return 0;
}
