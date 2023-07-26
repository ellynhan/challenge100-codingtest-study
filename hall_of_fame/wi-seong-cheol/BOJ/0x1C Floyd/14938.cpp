//
//  14938.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 5 5 4
 5 7 8 2 3
 1 4 5
 5 2 4
 3 2 3
 1 2 3
 [Output]
 23
 */
// 시간복잡도: O(n^3)
// 최악시간: 1,000,000
// 난이도: Gold 4
// Timer: 1h
// Url: https://www.acmicpc.net/problem/14938

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int INF = 0x3f3f3f3f;
int n, m, r;
int a, b, c;
int t[101];
int d[101][101];
int nxt[101][101];
bool vis[101];

void visit(int i, int j) {
    int st = i;
    while(st != j) {
        vis[st] = true;
        st = nxt[st][j];
    }
    vis[j] = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> r;
    for(int i = 1; i <= n; i++) {
        fill(d[i], d[i] + n + 1, INF);
        d[i][i] = 0;
    }
    for(int i = 1; i <= n; i++)
        cin >> t[i];
    while(r--) {
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;
        nxt[a][b] = b;
        nxt[b][a] = a;
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    nxt[i][j] = nxt[i][k];
                }
            }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        fill(vis + 1, vis + n + 1, false);
        int sum = 0;
        for(int j = 1; j <= n; j++) {
            if(d[i][j] > m) continue;
            visit(i, j);
        }
        for(int j = 1; j <= n; j++)
            if(vis[j]) sum += t[j];
        ans = max(ans, sum);
    }
    cout << ans;
    
    return 0;
}
