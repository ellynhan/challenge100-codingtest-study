//
//  10423.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 9 14 3
 1 2 9
 1 3 3
 1 4 8
 2 4 10
 3 4 11
 3 5 6
 4 5 4
 4 6 10
 5 6 5
 5 7 4
 6 7 7
 6 8 4
 7 8 5
 7 9 2
 8 9 5
 [Output]
 22
 */
// 시간복잡도: O(ElogE)
// 최악시간: 500,000
// 난이도: Gold 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/10423

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int n, m, k;
int x, u, v, w;
int ans, cnt;
vector<tuple<int, int, int>> edge;
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
    
    cin >> n >> m >> k;
    while(k--) {
        cin >> x;
        is_diff_group(0, x);
        cnt++;
    }
    while(m--) {
        cin >> u >> v >> w;
        edge.push_back({w, u, v});
    }
    sort(edge.begin(), edge.end());
    for(auto e: edge) {
        tie(w, u, v) = e;
        if(!is_diff_group(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n) break;
    }
    cout << ans;
    
    return 0;
}
