//
//  1719.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 6 10
 1 2 2
 1 3 1
 2 4 5
 2 5 3
 2 6 7
 3 4 4
 3 5 6
 3 6 7
 4 6 4
 5 6 2
 [Output]
 - 2 3 3 2 2
 1 - 1 4 5 5
 1 1 - 4 5 6
 3 2 3 - 6 6
 2 2 3 6 - 6
 5 5 3 4 5 -
 */
// 시간복잡도: O(n^3)
// 최악시간: 8,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1719

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, u, v, w;
int d[201][201];
int pre[201][201];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(d[i][j] > d[i][k] + d[k][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    pre[i][j] = pre[i][k];
                }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        fill(pre[i] + 1, pre[i] + n + 1, -1);
    }
    while(m--) {
        cin >> u >> v >> w;
        d[u][v] = w;
        d[v][u] = w;
        pre[u][v] = v;
        pre[v][u] = u;
    }
    
    floyd();
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i == j) cout << "- ";
            else cout << pre[i][j] << ' ';
        }
        cout << '\n';
    }
        
    
    return 0;
}
