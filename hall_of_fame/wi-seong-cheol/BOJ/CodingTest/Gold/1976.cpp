//
//  1976.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/11.
//

/*
 [Input]
 3
 2
 0 1 0
 1 0 1
 0 1 0
 1 1
 [Output]
 YES
 */
// 시간복잡도: O(n ^ 3)
// 최악시간: 8,000,000
// 난이도: Gold 4
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1976

#include <iostream>
#include <cstring>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, val, st, en;
int dist[201][201];
int route[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    memset(dist, INF, sizeof(dist));
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            cin >> val;
            if(i == j)
                dist[i][j] = 1;
            if(val == 1)
                dist[i][j] = 1;
        }
    for(int i = 0; i < m; i++) {
        cin >> val;
        route[i] = val - 1;
    }
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    bool flag = false;
    
    for(int i = 0; i < m - 1; i++) {
        st = route[i];
        en = route[i + 1];
        if(dist[st][en] == INF) {
            flag = true;
            break;
        }
    }
    
    if(flag) cout << "NO";
    else cout << "YES";
    
    return 0;
}
