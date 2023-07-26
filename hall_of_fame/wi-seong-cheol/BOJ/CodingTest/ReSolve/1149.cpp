//
//  1149.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/29.
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
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/1149

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[1001][3];
int R[1001], G[1001], B[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> R[i] >> G[i] >> B[i];
    d[0][0] = R[0];
    d[0][1] = G[0];
    d[0][2] = B[0];
    for(int i = 1; i < n; i++) {
        d[i][0] = min(d[i - 1][1], d[i - 1][2]) + R[i];
        d[i][1] = min(d[i - 1][0], d[i - 1][2]) + G[i];
        d[i][2] = min(d[i - 1][0], d[i - 1][1]) + B[i];
    }
    cout << *min_element(d[n - 1], d[n - 1] + 3);
    
    return 0;
}
