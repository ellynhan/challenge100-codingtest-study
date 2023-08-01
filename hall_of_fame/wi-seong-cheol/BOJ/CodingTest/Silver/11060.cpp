//
//  11060.cpp
//  main
//
//  Created by wi_seong on 2023/02/10.
//

/*
 [Input]
 10
 1 2 0 1 3 2 1 5 4 2
 [Output]
 5
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/11060

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x3f3f3f3f;
int n;
int a[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    fill(d, d + n, INF);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    d[0] = 0;
    for(int i = 0; i < n; i++) {
        if(d[i] == -1) break;
        for(int j = i + 1; j <= i + a[i]; j++)
            d[j] = min(d[j], d[i] + 1);
    }
    if(d[n - 1] == INF) cout << -1;
    else cout << d[n - 1];
    
    return 0;
}
