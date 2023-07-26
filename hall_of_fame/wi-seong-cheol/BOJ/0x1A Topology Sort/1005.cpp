//
//  1005.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 2
 4 4
 10 1 100 10
 1 2
 1 3
 2 4
 3 4
 4
 8 8
 10 20 1 5 8 7 1 43
 1 2
 1 3
 2 4
 2 5
 3 6
 5 7
 6 7
 7 8
 7
 [Output]
 120
 39
 */
// 시간복잡도: O(n + m)
// 최악시간: 101,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1005

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1001;
int n, k, u, v, w;
vector<int> adj[SIZE];
int a[SIZE];
int d[SIZE];
int deg[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) {
        adj[i].clear();
        deg[i] = 0;
        a[i] = 0;
        d[i] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while(t--) {
        init();
        cin >> n >> k;
        for(int i = 1; i <= n; i++)
            cin >> a[i];
        while(k--) {
            cin >> u >> v;
            adj[u].push_back(v);
            deg[v]++;
        }
        cin >> w;
        queue<int> Q;
        for(int i = 1; i <= n; i++)
            if(!deg[i]) {
                Q.push(i);
                d[i] = a[i];
            }
        while(!Q.empty()) {
            int cur = Q.front(); Q.pop();
            for(int nxt: adj[cur]) {
                d[nxt] = max(d[nxt], a[nxt] + d[cur]);
                deg[nxt]--;
                if(!deg[nxt]) Q.push(nxt);
            }
        }
        cout << d[w] << '\n';
    }
    
    return 0;
}
