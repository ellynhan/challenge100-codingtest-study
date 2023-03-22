//
//  1922.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 6
 9
 1 2 5
 1 3 4
 2 3 2
 2 4 7
 3 4 6
 3 5 11
 4 5 3
 4 6 8
 5 6 8
 [Output]
 23
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 4
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1922

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int ans, cnt;
int n, m, u, v, w;
vector<int> p(100001, -1);
tuple<int, int, int> edge[100001];

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
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        edge[i] = {w, u, v};
    }
    sort(edge, edge + m);
    for(int i = 0; i < m; i++) {
        tie(w, u, v) = edge[i];
        if(!is_diff_group(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << ans;
    
    return 0;
}
