//
//  2637.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 7
 8
 5 1 2
 5 2 2
 7 5 2
 6 5 2
 6 3 3
 6 4 4
 7 6 3
 7 4 5
 [Output]
 1 16
 2 16
 3 9
 4 17
 */
// 시간복잡도: O((n + m) * n)
// 최악시간: 20,000
// 난이도: Gold 2
// Timer: 1h
// Url: https://www.acmicpc.net/problem/2637

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n, m, x, y, k;
int d[101][101];
int deg[101];
vector<int> adj[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    while(m--) {
        cin >> x >> y >> k;
        adj[y].push_back(x);
        d[x][y] = k;
        deg[x]++;
    }
    queue<int> Q;
    for(int i = 1; i <= n; i++)
        if(deg[i] == 0) {
            Q.push(i);
            d[i][i] = 1;
        }
    while(!Q.empty()) {
        int cur = Q.front(); Q.pop();
        for(int nxt: adj[cur]) {
            int num = d[nxt][cur];
            d[nxt][cur] = 0;
            for(int k = 0; k < n; k++)
                d[nxt][k] += num * d[cur][k];
            deg[nxt]--;
            if(deg[nxt] == 0) Q.push(nxt);
        }
    }
    for(int i = 1; i < n; i++)
        if(d[n][i])
            cout << i << ' ' << d[n][i] << '\n';
    
    return 0;
}
