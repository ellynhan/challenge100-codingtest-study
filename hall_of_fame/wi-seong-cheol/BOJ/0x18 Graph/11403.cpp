//
//  11403.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3
 0 1 0
 0 0 1
 1 0 0
 [Output]
 1 1 1
 1 1 1
 1 1 1
 */
// 시간복잡도: O(n * (n + n)
// 최악시간: 20,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/11403

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n;
vector<int> adj[101];
bool vis[101];

void dfs(int x) {
    for(int i = 0; i < adj[x].size(); i++) {
        if(vis[adj[x][i]]) continue;
        vis[adj[x][i]] = true;
        dfs(adj[x][i]);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            if(x) adj[i].push_back(j);
        }
    
    for(int i = 0; i < n; i++) {
        fill(vis, vis + n + 1, false);
        dfs(i);
        for(int j = 0; j < n; j++)
            cout << vis[j] << ' ';
        cout << '\n';
    }
    
    return 0;
}
