//
//  2617.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 4
 2 1
 4 3
 5 1
 4 2
 [Output]
 2
 */
// 시간복잡도: O(n * (n + m))
// 최악시간: 510,000
// 난이도: Gold 4
// Timer: 40m
// Url: https://www.acmicpc.net/problem/2617

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v, ans;
vector<int> hv[101], li[101];
bool vis[101];

bool solve(int st, const vector<int> (&adj)[]) {
    queue<int> Q;
    int cnt = 0;
    fill(vis, vis + n + 1, false);
    Q.push(st);
    vis[st] = true;
    
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            if(vis[nxt]) continue;
            Q.push(nxt);
            vis[nxt] = true;
            cnt++;
        }
    }
    
    return cnt >= (n + 1) / 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        hv[u].push_back(v);
        li[v].push_back(u);
    }
    
    for(int i = 1; i <= n; i++)
        ans += (solve(i, hv) || solve(i, li));
    cout << ans;
    
    return 0;
}
