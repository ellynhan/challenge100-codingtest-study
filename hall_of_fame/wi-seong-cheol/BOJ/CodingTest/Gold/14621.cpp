//
//  14621.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 5 7
 M W W W M
 1 2 12
 1 3 10
 4 2 5
 5 2 5
 2 5 10
 3 4 3
 5 4 7
 [Output]
 34
 */
// 시간복잡도: O(ElogE)
// 최악시간: 50,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/14621

#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>

using namespace std;
int ans, cnt;
int n, m, u, v, w;
int gender[1001];
vector<int> p(1001, -1);
tuple<int, int, int> edge[10001];

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
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        char g; cin >> g;
        if(g == 'M') gender[i]++;
    }
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        u--; v--;
        edge[i] = {w, u, v};
    }
    sort(edge, edge + m);
    for(int i = 0; i < m; i++) {
        tie(w, u, v) = edge[i];
        if(gender[u] == gender[v]) continue;
        if(!is_diff_group(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n - 1) break;
    }
    if(cnt != n - 1) cout << -1;
    else cout << ans;
    
    return 0;
}
