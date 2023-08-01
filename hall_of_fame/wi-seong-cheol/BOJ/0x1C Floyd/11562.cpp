//
//  11562.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 3
 1 2 0
 2 3 1
 3 4 0
 7
 1 1
 1 2
 2 1
 1 4
 4 1
 2 3
 4 3
 [Output]
 0
 0
 1
 0
 2
 0
 1
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 15,625,000
// 난이도: Gold 3
// Timer: 20m
// Url: https://www.acmicpc.net/problem/11562

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, k, u, v, b;
int d[251][251];

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
    for(int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        d[i][i] = 0;
    }
    while(m--) {
        cin >> u >> v >> b;
        d[u][v] = 0;
        d[v][u] = !b;
    }
    floyd();
    
    cin >> k;
    while(k--) {
        cin >> u >> v;
        cout << d[u][v] << '\n';
    }
    
    return 0;
}
