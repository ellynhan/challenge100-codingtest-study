//
//  12995.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/08.
//

/*
 [Input]
 4 2
 1 2
 2 3
 3 4
 [Output]
 3
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000
// 난이도: Platinum 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/12995

#include <iostream>
#include <vector>

using namespace std;
#define ll long long
const ll mod = 1e9 + 7;
int n, k, u, v;
vector<int> adj[51];
ll d[51][51];
ll ans;

void dfs(int cur, int parent) {
    d[cur][1] = 1;
    
    for(int nxt: adj[cur]) {
        if(nxt == parent) continue;
        dfs(nxt, cur);

        vector<int> tmp(n + 1, 0);

        for(int i = n; i >= 1; i--) {
            for(int j = n - i; j >= 1; j--) {
                tmp[j + i] += d[cur][j] * d[nxt][i];
                tmp[j + i] %= mod;
            }
        }
        for(int i = 1; i <= n; i++) {
            d[cur][i] += tmp[i];
            d[cur][i] %= mod;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);

    for(int i = 0; i < n; i++) {
        ans += d[i][k];
        ans %= mod;
    }

    cout << ans;

    return 0;
}
