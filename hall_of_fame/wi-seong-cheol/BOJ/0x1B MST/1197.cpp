//
//  1197.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
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
int v, e, a, b, cost, cnt, ans;
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
    
    cin >> v >> e;
    for(int i = 0; i < e; i++) {
        cin >> a >> b >> cost;
        edge[i] = {cost, a, b};
    }
    sort(edge, edge + e);
    for(int i = 0; i < e; i++) {
        tie(cost, a, b) = edge[i];
        if(!is_diff_group(a, b)) continue;
        ans += cost;
        cnt++;
        if(cnt == v - 1) break;
    }
    cout << ans;
    
    return 0;
}
