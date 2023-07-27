//
//  1197.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 3 3
 1 2 1
 2 3 2
 1 3 3
 [Output]
 3
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1197

#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;
int ans, cnt;
int n, m, u, v, w;
vector<int> p(10001, -1);
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
        if(!is_diff_group(u, v))
            continue;
        ans += w;
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << ans;
    
    return 0;
}
