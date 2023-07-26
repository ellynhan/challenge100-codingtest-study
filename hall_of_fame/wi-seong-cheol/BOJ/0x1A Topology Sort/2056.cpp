//
//  2056.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 5 0
 1 1 1
 3 1 2
 6 1 1
 1 2 2 4
 8 2 2 4
 4 3 3 5 6
 [Output]
 23
 */
// 시간복잡도: O(n + m)
// 최악시간: 100,000,000
// 난이도: Gold 4
// Timer: 40h
// Url: https://www.acmicpc.net/problem/2056

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
int n, m, u, w, k, ans;
vector<int> adj[10001];
int deg[10001];
int a[10001];
int d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> w >> k;
        for(int j = 0; j < k; j++) {
            cin >> u;
            adj[u].push_back(i);
            deg[i]++;
        }
        a[i] = w;
    }
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
    for(int i = 1; i <= n; i++) ans = max(ans, d[i]);
    cout << ans;
    
    return 0;
}
