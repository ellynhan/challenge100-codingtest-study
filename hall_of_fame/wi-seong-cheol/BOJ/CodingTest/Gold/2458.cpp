//
//  2458.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/09.
//

/*
 [Input]
 6 7
 1 3
 1 5
 3 4
 5 4
 4 2
 4 6
 5 2
 [Output]
 2
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2458

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, u, v, ans;
int d[501][501];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(i == j) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(d, INF, sizeof(d));
    cin >> n >> m;
    while(m--) {
        cin >> u >> v;
        d[u][v] = 1;
    }
    floyd();
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++)
            if(d[i][j] != INF || d[j][i]!= INF) cnt++;
        if(cnt == n - 1) ans++;
    }
    cout << ans;
    
    return 0;
}
