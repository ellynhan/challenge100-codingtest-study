//
//  1707.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 3 2
 1 3
 2 3
 4 4
 1 2
 2 3
 3 4
 4 2
 [Output]
 YES
 NO
 */
// 시간복잡도: O(n * m)
// 최악시간: 4,000,000,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1707

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 20001;
int n, m;
int gr[SIZE];
vector<int> adj[SIZE];

bool solve() {
    for(int i = 1; i <= n; i++) {
        if(gr[i] != -1) continue;
        queue<int> Q;
        Q.push(i);
        gr[i] = 0;
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nxt: adj[cur]) {
                if(gr[nxt] != -1) {
                    if(gr[nxt] == gr[cur]) return false;
                    continue;
                }
                gr[nxt] = (gr[cur] + 1) % 2;
                Q.push(nxt);
            }
        }
    }
    
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        fill(gr, gr + n + 1, -1);
        for(int i = 1; i <= n; i++)
            adj[i].clear();
        while(m--) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
    
    return 0;
}
