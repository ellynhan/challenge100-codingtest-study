//
//  1389.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 5
 1 3
 1 4
 4 5
 4 3
 3 2
 [Output]
 3
 */
// 시간복잡도: O(n * m)
// 최악시간: 500,000
// 난이도: Silver 1
// Timer: 40m
// Url: https://www.acmicpc.net/problem/1389

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;
#define X first
#define Y second
int n, m, u, v;
vector<int> adj[101];
bool vis[101];
int cnt[101];
int sum[101];

void bfs(int st) {
    vis[st] = true;
    queue<pair<int, int>> Q;
    for(int x: adj[st]) {
        Q.push({x, 1});
        cnt[x] = 1;
        vis[x] = true;
    }
    while (!Q.empty()) {
        auto cur = Q.front(); Q.pop();
        for(int nxt: adj[cur.X]) {
            if(vis[nxt]) continue;
            cnt[nxt] = cur.Y + 1;
            vis[nxt] = true;
            Q.push({nxt, cur.Y + 1});
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        fill(cnt + 1, cnt + n + 1, 0);
        bfs(i);
        sum[i] = accumulate(cnt, cnt + n + 1, 0);
    }
    int mn = *min_element(sum + 1, sum + n + 1);
    for(int i = 1; i <= n; i++)
        if(mn == sum[i]) {
            cout << i;
            break;
        }
            
    
    return 0;
}
