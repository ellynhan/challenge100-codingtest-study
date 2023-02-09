//
//  17182.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/01/02.
//

/*
 [Input]
 3 0
 0 30 1
 1 0 29
 28 1 0
 [Output]
 2
 */
// 시간복잡도: O(n ^ 3 + 2^n)
// 최악시간: 2,024
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/17182

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int n, k;
int ans = INF;
int d[11][11];
int vis[11];

void func(int idx, int st, int sum) {
    if(idx == n) {
        ans = min(ans, sum);
        return;
    }
    for(int i = 0; i < n; i++) {
        if(!vis[i] && st != i) {
            vis[st] = true;
            func(idx + 1, i, sum + d[st][i]);
            vis[st] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> d[i][j];
    for(int k = 0; k < n; k++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    func(1, k, 0);
    cout << ans;
    
    return 0;
}
