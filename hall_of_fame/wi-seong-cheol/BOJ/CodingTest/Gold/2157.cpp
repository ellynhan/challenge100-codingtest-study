//
//  2157.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/19.
//

/*
 [Input]
 3 3 5
 1 3 10
 1 2 5
 2 3 3
 1 3 4
 3 1 100
 [Output]
 10
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 90,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2157

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define X first
#define Y second
int ans;
int n, m, k;
int u, v, w;
vector<pair<int, int>> adj[301];
int d[301][301];    // 정점, 이동횟수 - 점수

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    while(k--) {
        cin >> u >> v >> w;
        if(u > v) continue;
        adj[u].push_back({w, v});
    }
    for(auto element: adj[1])
        d[element.Y][2] = max(d[element.Y][2], element.X);
    for(int i = 1; i <= n; i++) {    // 정점
        for(int j = 2; j <= m; j++) {    // 이동횟수
            if(d[i][j] == 0) continue;
            for(auto element: adj[i]) {
                d[element.Y][j + 1] = max(d[element.Y][j + 1], element.X + d[i][j]);
            }
        }
    }
    for(int i = 2; i <= m; i++)
        ans = max(ans, d[n][i]);
    cout << ans;
    
    return 0;
}
