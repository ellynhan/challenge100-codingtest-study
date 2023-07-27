//
//  2887.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5
 11 -15 -15
 14 -5 -15
 -1 -1 -5
 10 -4 -1
 19 -4 19
 [Output]
 4
 */
// 시간복잡도: O(ElogE)
// 최악시간: 1,500,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2887

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
#define X first
#define Y second
int n, x, y, z;
int ans, cnt;
vector<pair<int,int>> c_x, c_y, c_z;
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
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        c_x.push_back({x, i});
        c_y.push_back({y, i});
        c_z.push_back({z, i});
    }
    
    sort(c_x.begin(), c_x.end());
    sort(c_y.begin(), c_y.end());
    sort(c_z.begin(), c_z.end());
    
    for(int i = 1; i < n; i++) {
        edge.push_back({abs(c_x[i - 1].X - c_x[i].X), c_x[i - 1].Y, c_x[i].Y});
        edge.push_back({abs(c_y[i - 1].X - c_y[i].X), c_y[i - 1].Y, c_y[i].Y});
        edge.push_back({abs(c_z[i - 1].X - c_z[i].X), c_z[i - 1].Y, c_z[i].Y});
    }
    
    sort(edge.begin(), edge.end());
    
    for(auto e: edge) {
        tie(z, x, y) = e;
        if(!is_diff_group(x, y)) continue;
        cnt++;
        ans += z;
        if(cnt == n - 1) break;
    }
    cout << ans;
    
    return 0;
}
