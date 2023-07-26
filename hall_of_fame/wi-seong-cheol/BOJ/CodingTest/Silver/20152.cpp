//
//  20152.cpp
//  main
//
//  Created by wi_seong on 2023/02/09.
//

/*
 [Input]
 0 30
 [Output]
 3814986502092304
 */
// 시간복잡도: O(n^2)
// 최악시간: 900
// 난이도: Silver 2
// Timer: 30m
// Url: https://www.acmicpc.net/problem/20152

#include <iostream>
#include <algorithm>

using namespace std;
#define ll long long
int n, m;
ll d[31][31];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    if(n > m) swap(n, m);
    fill(d[n], d[n] + m + 1, 1);
    for(int i = n + 1; i <= m; i++)
        for(int j = i; j <= m; j++) {
            d[i][j] = d[i - 1][j] + d[i][j - 1];
        }
    cout << d[m][m];
    
    return 0;
}
