//
//  11725.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 1 6
 6 3
 3 5
 4 1
 2 4
 4 7
 [Output]
 4
 6
 1
 3
 1
 4
 */
// 시간복잡도: O(n + e)
// 최악시간: 200,000
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11725

#include <iostream>
#include <vector>

using namespace std;
const int MX = 100'001;
int n, u, v;
int root[MX];
vector<int> adj[MX];

void dfs(int cur) {
    for(int nxt: adj[cur]) {
        if(root[cur] == nxt) continue;
        root[nxt] = cur;
        dfs(nxt);
    }
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
    dfs(1);
    for(int i = 2; i <= n; i++)
        cout << root[i] << '\n';
    
    return 0;
}
