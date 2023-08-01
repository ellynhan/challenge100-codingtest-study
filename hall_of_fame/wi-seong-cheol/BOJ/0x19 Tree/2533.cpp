//
//  2533.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 8
 1 2
 1 3
 1 4
 2 5
 2 6
 4 7
 4 8
 [Output]
 3
 */
// 시간복잡도: O(logn)
// 최악시간: 6
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2533

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MXN = 1'000'001;
int n, u, v;
vector<int> adj[MXN], tree[MXN], state[MXN];

void mktree(int cur, int prev) {
    for(int nxt: adj[cur]) {
        if(nxt == prev) continue;
        tree[cur].push_back(nxt);
        mktree(nxt, cur);
    }
}

int dp(int cur, bool isEarlyAdaptor) {
    if(state[cur][isEarlyAdaptor] != -1)
        return state[cur][isEarlyAdaptor];
    
    int val = 0;
    if(isEarlyAdaptor)
        for(int nxt: tree[cur])
            val += min(dp(nxt, false), dp(nxt, true));
    else
        for(int nxt: tree[cur])
            val += dp(nxt, true);
    
    return state[cur][isEarlyAdaptor] = val + isEarlyAdaptor;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        state[i].push_back(-1);
        state[i].push_back(-1);
    }
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    mktree(1, -1);
    cout << min(dp(1, false), dp(1, true));
    
    return 0;
}
