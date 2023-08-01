//
//  13141.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 10
 1 2 1
 2 3 1
 3 4 1
 4 5 1
 1 3 10
 2 4 10
 3 5 10
 1 4 7
 2 5 7
 1 5 9
 [Output]
 6.5
 */
// 시간복잡도: O(n^3)
// 최악시간: 8,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/13141

#include <iostream>
#include <algorithm>
#include <tuple>

using namespace std;
#define ll long long
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
double ans = INF;
int d[201][201];
tuple<int, int, int> edges[20005];

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
    for(int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        d[u][v] = min(d[u][v], w);
        d[v][u] = min(d[v][u], w);
        edges[i] = {u, v, w};
    }
    floyd();
    for(int i = 1; i <= n; i++) {
        double total = 0;
        for(int j = 0; j < m; j++) {
            tie(u, v, w) = edges[j];
            total = max(total, (double)(w + d[i][u] + d[i][v]) / 2);
        }
        ans = min(ans, total);
    }
    cout << fixed;
    cout.precision(1);
    cout << ans;
    
    return 0;
}
