//
//  24955.cpp
//  main
//
//  Created by wi_seong on 2023/01/16.
//

/*
 [Input]
 3 2
 10 9 1
 1 2
 2 3
 1 3
 3 1
 [Output]
 1091
 1910
 */
// 시간복잡도: O(n * m)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/24955

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define ll long long
#define X first
#define Y second
const int mod = 1e9 + 7;
int n, m;
int a[1001];
vector<vector<int>> road(1001);

ll concat(ll x, ll y) {
    ll ans = x;

    for(ll i = y; i > 0; i /= 10) {
        ans = (ans * 10) % mod;
    }
    ans += y;
    ans %= mod;

    return ans;
}

long long bfs(int start, int end) {
    vector<long long> ans(n + 1, -1);
    queue<int> Q;
    Q.push(start);
    ans[start] = a[start];
    while(!Q.empty()) {
        int x = Q.front(); Q.pop();
        for(int nx : road[x]) {
            if (ans[nx] != -1) continue;
            ans[nx] = concat(ans[x], a[nx]);
            Q.push(nx);
        }
    }
    return ans[end];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        road[u].push_back(v);
        road[v].push_back(u);
    }
    while(m--) {
        int u, v;
        cin >> u >> v;
        cout << bfs(u, v) << '\n';
    }
    
    return 0;
}
