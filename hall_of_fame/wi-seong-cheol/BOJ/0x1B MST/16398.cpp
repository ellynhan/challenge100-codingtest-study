//
//  16398.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3
 0 2 3
 2 0 1
 3 1 0
 [Output]
 3
 */
// 시간복잡도: O(n^2(logn))
// 최악시간: 6,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/16398

#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
#define ll long long
int n, w, cnt;
ll ans;
vector<tuple<int, int, int>> edge;
vector<int> p(1001, -1);

int find(int x) {
    if(p[x] < 0) return x;
    return p[x] = find(p[x]);
}

bool is_diff_group(int a, int b) {
    a = find(a);
    b = find(b);
    if(a == b) return false;
    if(p[a] == p[b]) p[a]--;
    if(p[a] < p[b]) p[b] = a;
    else p[a] = b;
    return true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> w;
            if(i == j) continue;
            edge.push_back({w, i, j});
        }

    sort(edge.begin(), edge.end());

    for(auto e: edge) {
        int w, a, b;
        tie(w, a, b) = e;
        if(!is_diff_group(a, b)) continue;
        cnt++;
        ans += w;
        if(cnt == n - 1) break;
    }
    cout << ans;

    return 0;
}
