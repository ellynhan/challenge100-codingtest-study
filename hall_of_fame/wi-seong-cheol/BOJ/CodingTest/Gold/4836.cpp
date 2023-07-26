//
//  4836.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/22.
//

/*
 [Input]
 3
 1.0 1.0
 2.0 2.0
 2.0 4.0
 [Output]
 3.41
 */
// 시간복잡도: O(n ^ 2 + ElogE)
// 최악시간: 100,050,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/4836

#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

using namespace std;
#define X first
#define Y second
int n, cnt;
double ans;
double x, y, u, v, w;
pair<double, double> star[10001];
tuple<double, double, double> edge[10001];
vector<int> p(10001, -1);

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
        cin >> x >> y;
        star[i] = {x, y};
    }
    int m = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            w = sqrt(pow(star[i].X - star[j].X, 2) + pow(star[i].Y - star[j].Y, 2));
            edge[m++] = {w, i, j};
        }
    }
    sort(edge, edge + m);
    for(int i = 0; i < m; i++) {
        tie(w, u, v) = edge[i];
        if(!is_diff_group(u, v)) continue;
        ans += w;
        cnt++;
        if(cnt == n - 1) break;
    }
    cout << fixed;
    cout.precision(2);
    cout << ans;
    
    return 0;
}
