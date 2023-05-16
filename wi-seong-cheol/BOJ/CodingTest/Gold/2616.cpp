//
//  2616.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/03/07.
//

/*
 [Input]
 7
 35 40 50 10 30 45 60
 2
 [Output]
 240
 */
// 시간복잡도: O(n)
// 최악시간: 50,000
// 난이도: Gold 3
// Timer: 30m
// Url: https://www.acmicpc.net/problem/2616

#include <iostream>

using namespace std;
int n, m, x;
int sum[50001];
int d[4][50001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }
    cin >> m;
    for(int i = 1; i <= 3; i++) {
        for(int j = i * m; j <= n; j++) {
            d[i][j] = max(d[i][j - 1], d[i - 1][j - m] + sum[j] - sum[j - m]);
        }
    }
    cout << d[3][n];
    
    return 0;
}
