//
//  13910.cpp
//  main
//
//  Created by wi_seong on 2023/02/27.
//

/*
 [Input]
 3 2
 1 2
 [Output]
 1
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Gold 5
// Timer: 40m
// Url: https://www.acmicpc.net/problem/13910

#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 0x7f7f7f7f;
int n, m;
int a[101];
int d[20001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
        cin >> a[i];
    fill(d, d + 20001, INF);
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++) {
            if(i == j) d[a[i]] = 1;
            else d[a[i] + a[j]] = 1;
        }
    for(int i = 1; i <= n; i++) {
        if(d[i] == 1) continue;
        for(int j = 1; j <= i / 2; j++) {
            if(d[i - j] == -1 || d[j] == -1) continue;
            d[i] = min(d[i], d[i - j] + d[j]);
        }
        if(d[i] == INF) d[i] = -1;
    }
    cout << d[n];
    
    return 0;
}
