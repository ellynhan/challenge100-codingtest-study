//
//  12978.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/16.
//

/*
 [Input]
 5
 4 5
 4 2
 2 3
 1 2
 [Output]
 2
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 3
// Timer: 40m
// Url: https://www.acmicpc.net/problem/12978

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;
const int MX = 0x7f7f7f7f;
int n, u, v;
vector<int> adj[100001];
int d[100001][2];

int dfs(int cur, int parent, int isPolice) {
    if(d[cur][isPolice] != MX) {
        return d[cur][isPolice];
    }
    
    int police = 0;
    if(isPolice) police++;
    for(int nxt: adj[cur]) {
        if(nxt == parent) continue;
        if(isPolice) {
            police += min(dfs(nxt, cur, 1), dfs(nxt, cur, 0));
        } else {
            police += dfs(nxt, cur, 1);
        }
    }
    
    return d[cur][isPolice] = police;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    memset(d, MX, sizeof(d));
    
    cout << min(dfs(1, 0, 0), dfs(1, 0, 1));
    
    return 0;
}
