//
//  13418.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 5
 0 1 1
 1 2 0
 1 4 0
 4 2 1
 3 4 1
 2 3 0
 [Output]
 8
 */
// 시간복잡도: O(ElogE)
// 최악시간: 2,500,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/13418

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n, m;
int u, v, w;
int ans, cnt, mn, mx;
vector<tuple<int, int, int>> edge;
vector<int> p(1001, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_gruop(int u, int v) {
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
    
    cin >> n >> m;
    for(int i = 0; i < m + 1; i++) {
        cin >> u >> v >> w;
        w = (w + 1) % 2;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());
    for(auto e: edge) {
        tie(w, u, v) = e;
        if(!is_diff_gruop(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n) break;
    }
    mn = ans * ans;
    ans = cnt = 0;
    fill(p.begin(), p.end(), -1);
    sort(edge.begin(), edge.end(), greater<>());
    for(auto e: edge) {
        tie(w, u, v) = e;
        if(!is_diff_gruop(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n) break;
    }
    mx = ans * ans;
    cout << mx - mn;
    
    return 0;
}
