//
//  1495.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/24.
//

/*
 [Input]
 14 40 243
 74 39 127 95 63 140 99 96 154 18 137 162 14 88
 [Output]
 238
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 50,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/1495

#include <iostream>

using namespace std;
int n, m, s;
int a[1001], d[51][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> s >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(s + a[0] <= m) d[1][s + a[0]] = 1;
    if(s - a[0] >= 0) d[1][s - a[0]] = 1;
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < 1001; j++) {
            if(d[i][j] == 0) continue;
            if(j + a[i] <= m) d[i + 1][j + a[i]] = 1;
            if(j - a[i] >= 0) d[i + 1][j - a[i]] = 1;
        }
    }
    int mx = -1;
    for(int i = 0; i <= m; i++)
        if(d[n][i]) mx = i;
    cout << mx;
    
    return 0;
}
