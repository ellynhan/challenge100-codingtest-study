//
//  1766.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 2
 4 2
 3 1
 [Output]
 3 1 4 2
 */
// 시간복잡도: O((n + m)logn)
// 최악시간: 660,000
// 난이도: Gold 2
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1766

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v;
vector<int> adj[32001];
int deg[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }
    priority_queue<int, vector<int>, greater<>> pq;
    for(int i = 1; i <= n; i++)
        if(!deg[i]) pq.push(i);
    while(!pq.empty()) {
        int cur = pq.top(); pq.pop();
        cout << cur << ' ';
        for(int nxt: adj[cur]) {
            deg[nxt]--;
            if(!deg[nxt]) pq.push(nxt);
        }
    }
    
    return 0;
}
