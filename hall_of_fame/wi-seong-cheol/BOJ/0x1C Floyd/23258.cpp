//
//  23258.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 4 2
 0 100 1 0
 100 0 0 100
 1 0 0 1
 0 100 1 0
 3 1 4
 2 4 1
 [Output]
 200
 -1
 */
// 시간복잡도: O(n^3)
// 최악시간: 27,000,000
// 난이도: Platinum 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/23258

#include <iostream>
#include <algorithm>

using namespace std;
const int SIZE = 301;
const int INF = 0x3f3f3f3f;
int n, m, cost, st, en;
int d[SIZE][SIZE][SIZE];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                d[k][i][j] = min(d[k - 1][i][j], d[k - 1][i][k] + d[k - 1][k][j]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            cin >> d[0][i][j];
            if(i == j) continue;
            if(d[0][i][j] == 0)
                d[0][i][j] = INF;
        }
    floyd();
    while(m--) {
        cin >> cost >> st >> en;
        if(d[cost - 1][st][en] == INF) cout << "-1\n";
        else cout << d[cost - 1][st][en] << '\n';
    }

    return 0;
}
