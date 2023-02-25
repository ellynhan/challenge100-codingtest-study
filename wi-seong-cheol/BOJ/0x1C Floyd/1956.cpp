//
//  1956.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 4
 1 2 1
 3 2 1
 1 3 5
 2 3 2
 [Output]
 3
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 64,000,000
// 난이도: Gold 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/1956

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
int ans = INF;
int d[401][401];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        fill(d[i] + 1, d[i] + n + 1, INF);
    while(m--) {
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    floyd();
    for(int i = 1; i < n; i++)
        for(int j = i + 1; j <= n; j++)
            ans = min(ans, d[i][j] + d[j][i]);
    if(ans >= INF) cout << -1;
    else cout << ans;
    
    return 0;
}
