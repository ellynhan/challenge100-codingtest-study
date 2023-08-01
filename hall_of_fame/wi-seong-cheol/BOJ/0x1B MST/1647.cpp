//
//  1647.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7 12
 1 2 3
 1 3 2
 3 2 1
 2 5 2
 3 4 4
 7 3 6
 5 1 5
 1 6 2
 6 4 1
 6 5 3
 4 5 3
 6 7 4
 [Output]
 8
 */
// 시간복잡도: O(ElogE)
// 최악시간: 6,000,000
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1647

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
#define ll long long
int n, m, a, b, c;
int cnt, mc;
ll ans;
vector<tuple<int, int, int>> edge;
vector<int> p(100001, -1);

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
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for(auto e: edge) {
        tie(c, a, b) = e;
        if(!is_diff_group(a, b)) continue;
        cnt++;
        ans += c;
        mc = max(mc, c);
        if(cnt == n - 1) break;
    }
    cout << ans - mc;
    
    return 0;
}
