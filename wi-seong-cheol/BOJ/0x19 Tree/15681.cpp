//
//  15681.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9 5 3
 1 3
 4 3
 5 4
 5 6
 6 7
 2 3
 9 6
 6 8
 5
 4
 8
 [Output]
 9
 4
 1
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15681

#include <iostream>
#include <vector>

using namespace std;
const int MX = 100'001;
int n, r, q, u, v, root;
int subTreeSize[MX];
bool vis[MX];
vector<int> adj[MX];

int countSubtreeNode(int cur) {
    vis[cur] = true;
    for(auto nxt: adj[cur]) {
        if(vis[nxt]) continue;
        subTreeSize[cur] += countSubtreeNode(nxt);
    }
    subTreeSize[cur]++;
    return subTreeSize[cur];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> r >> q;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    countSubtreeNode(r);
    while(q--) {
        cin >> root;
        cout << subTreeSize[root] << '\n';
    }
    
    return 0;
}
