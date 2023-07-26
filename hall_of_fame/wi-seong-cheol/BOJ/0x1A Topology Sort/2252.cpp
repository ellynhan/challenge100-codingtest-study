//
//  2252.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 2
 1 3
 2 3
 [Output]
 1 2 3
 */
// 시간복잡도: O(n + m)
// 최악시간: 132,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2252

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m;
int deg[32001];
vector<int> adj[32001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        deg[b]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) Q.push(i);
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        cout << cur << ' ';
        for(int nxt: adj[cur]) {
            deg[nxt]--;
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }
    
    return 0;
}
