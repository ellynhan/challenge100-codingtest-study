//
//  27212.cpp
//  main
//
//  Created by wi_seong on 2023/01/14.
//

/*
 [Input]
 2 3 2
 1 10
 10 10
 1 2
 1 2 2
 [Output]
 20
 */
// 시간복잡도: O(nm)
// 최악시간: 1,000,000
// 난이도: Gold 3
// Timer: 3h
// Url: https://www.acmicpc.net/problem/27212

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n, m, c;
int a[1001];
int b[1001];
ll w[17][17];
ll d[1001][1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> c;
    for(int i = 1; i <= c; i++)
        for(int j = 1; j <= c; j++)
            cin >> w[i][j];
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            ll val = w[a[i]][b[j]];
            d[i][j] = max({d[i - 1][j - 1] + val, d[i][j - 1], d[i - 1][j]});
        }
    }
    
    cout << d[n][m];
    
    return 0;
}
