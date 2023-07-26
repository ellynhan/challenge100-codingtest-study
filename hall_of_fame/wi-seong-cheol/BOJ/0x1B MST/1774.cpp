//
//  1774.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 2
 1 1
 3 1
 2 3
 4 3
 1 4
 4 1
 [Output]
 4.00
 */
// 시간복잡도: O(ElogE)
// 최악시간: 6,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1774

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <cmath>
#include <stdio.h>

using namespace std;
#define ll long long
#define X first
#define Y second
int n, m, a, b;
ll w;
pair<int, int> adj[1001];
vector<tuple<ll, int, int>> edge;
vector<int> p(1001, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u);
    v = find(v);
    if(u == v) return false;
    if(p[u] == p[v]) p[u]--;
    if(p[u] < p[v]) p[v] = u;
    else p[u] = v;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double ans = 0;
    int cnt = 0;
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a >> b;
        adj[i] = {a, b};
    }
    for(int i = 1; i <= n - 1; i++) {
        for(int j = i + 1; j <= n; j++) {
            w = pow(adj[i].X - adj[j].X, 2) + pow(adj[i].Y - adj[j].Y, 2);
            edge.push_back({w, i, j});
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> a >> b;
        w = pow(adj[a].X - adj[b].X, 2) + pow(adj[a].Y - adj[b].Y, 2);
        if(!is_diff_group(a, b)) continue;
        cnt++;
    }
    
    sort(edge.begin(), edge.end());
    
    for(auto e: edge) {
        if(cnt == n - 1) break;
        tie(w, a, b) = e;
        if(!is_diff_group(a, b)) continue;
        cnt++;
        ans += sqrt(w);
    }
    printf("%.2lf\n", ans);
    
    return 0;
}
