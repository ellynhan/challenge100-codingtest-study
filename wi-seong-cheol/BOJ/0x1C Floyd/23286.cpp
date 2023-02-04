//
//  23286.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 6 3
 1 2 12
 3 2 8
 1 3 5
 2 5 3
 3 4 4
 2 4 8
 3 4
 1 2
 5 1
 [Output]
 4
 8
 -1
 */
// 시간복잡도: O(n^3)
// 최악시간: 27,000,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/23286

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, t, u, v, w, st, en;
int d[301][301];

void init() {
    for(int i = 1; i <= n; i++) {
        fill(d[i] + 1, d[i] + n + 1, INF);
        d[i][i] = 0;
    }
}

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> t;
    init();
    while(m--) {
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    floyd();
    while(t--) {
        cin >> st >> en;
        if(d[st][en] == INF) cout << "-1\n";
        else cout << d[st][en] << '\n';
    }
    
    return 0;
}
