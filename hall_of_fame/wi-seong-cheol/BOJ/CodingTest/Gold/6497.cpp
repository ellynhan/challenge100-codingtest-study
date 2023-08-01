//
//  6497.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 7 11
 0 1 7
 0 3 5
 1 2 8
 1 3 9
 1 4 7
 2 4 5
 3 4 15
 3 5 6
 4 5 8
 4 6 9
 5 6 11
 [Output]
 51
 */
// 시간복잡도: O(ElogE)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/6497

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;
int ans, cnt, sum;
int n, m, u, v, w;
vector<tuple<int, int, int>> edge;
vector<int> p;

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

void init() {
    ans = cnt = sum = 0;
    p.clear();
    p.resize(n, -1);
    edge.clear();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(1) {
        cin >> n >> m;
        if(n == 0 || m == 0) break;
        init();
        for(int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edge.push_back({w, u, v});
            sum += w;
        }
        sort(edge.begin(), edge.end());
        for(auto e: edge) {
            tie(w, u, v) = e;
            if(!is_diff_group(u, v)) continue;
            ans += w;
            cnt++;
            if(cnt == n - 1) break;
        }
        cout << sum - ans << '\n';
    }
    
    return 0;
}
