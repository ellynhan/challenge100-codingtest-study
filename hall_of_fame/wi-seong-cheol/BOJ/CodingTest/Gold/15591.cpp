//
//  15591.cpp
//  main
//
//  Created by wi_seong on 2023/01/17.
//

/*
 [Input]
 4 3
 1 2 3
 2 3 2
 2 4 4
 1 2
 4 1
 3 1
 [Output]
 3
 0
 2
 */
// 시간복잡도: O(n * m)
// 최악시간: 5,000
// 난이도: Gold 5
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15591

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
#define from first
#define val second
int n, m, p, q, r, k, v;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
vector<pair<int, int>> USADO[5001];

int bfs() {
    int cnt = 0;
    queue<int> Q;
    Q.push(v);
    bool vis[n];
    fill(vis, vis + n + 1, false);
    vis[v] = true;
    
    while(!Q.empty()) {
        int idx = Q.front(); Q.pop();
        for(auto cur: USADO[idx]) {
            int nx = cur.from;
            int usado = cur.val;
            if(vis[nx] || usado < k) continue;
            cnt++;
            vis[nx] = true;
            Q.push(nx);
        }
    }
    
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < n - 1; i++) {
        cin >> p >> q >> r;
        USADO[p].push_back({q, r});
        USADO[q].push_back({p, r});
    }
    while(m--) {
        cin >> k >> v;
        cout << bfs() << '\n';
    }
    
    return 0;
}
