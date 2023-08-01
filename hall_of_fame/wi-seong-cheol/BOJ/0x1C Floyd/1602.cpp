//
//  1602.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7 8 5
 2 3 5 15 4 4 6
 1 2 20
 1 4 20
 1 5 50
 2 3 10
 3 4 10
 3 5 10
 4 5 15
 6 7 10
 1 5
 1 6
 5 1
 3 1
 6 7
 [Output]
 45
 -1
 45
 35
 16
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 125,000,000
// 난이도: Platinum 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1602

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second
const int INF = 0x3f3f3f3f;
int n, m, q, u, v, w, st, en;
int dog[501];
int cost[501][501];
int dog_cost[501][501];
vector<pair<int, int>> dog_p;

void floyd() {
    for(int k = 0; k < n; k++) {
        int vis = dog_p[k].Y;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                int wait = max(dog_cost[i][vis], dog_cost[vis][j]);
                if(cost[i][j] + dog_cost[i][j] > cost[i][vis] + cost[vis][j] + wait) {
                    cost[i][j] = cost[j][i] = cost[i][vis] + cost[vis][j];
                    dog_cost[i][j] = dog_cost[j][i] = wait;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> dog[i];
        dog_p.push_back({dog[i], i});
    }
    sort(dog_p.begin(), dog_p.end());
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;
            cost[i][j] = INF;
        }
    while(m--) {
        cin >> u >> v >> w;
        int wait = max(dog[u], dog[v]);
        cost[u][v] = cost[v][u] = w;
        dog_cost[u][v] = dog_cost[v][u] = wait;
    }
    floyd();

    while(q--) {
        cin >> st >> en;
        if(cost[st][en] == INF) cout << "-1\n";
        else cout << cost[st][en] + dog_cost[st][en] << '\n';
    }

    return 0;
}
