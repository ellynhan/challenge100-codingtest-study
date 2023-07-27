//
//  1463.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 26 40 83
 49 60 57
 13 89 99
 [Output]
 96
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1149

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int r[1001], g[1001], b[1001];
int d[1001][3];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> r[i] >> g[i] >> b[i];
    d[0][0] = r[0];
    d[0][1] = g[0];
    d[0][2] = b[0];
    for(int i = 1; i < n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + r[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + g[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + b[i];
    }
    cout << *min_element(d[n - 1], d[n - 1] + 3);
    
    return 0;
}
