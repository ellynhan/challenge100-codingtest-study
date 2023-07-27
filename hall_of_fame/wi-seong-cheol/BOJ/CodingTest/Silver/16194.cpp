//
//  16194.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 4
 3 5 15 16
 [Output]
 10
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 1,000,000
// 난이도: Silver 1
// Timer: 20m
// Url: https://www.acmicpc.net/problem/16194

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int card[1001];
int d[1001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> card[i];
    for(int i = 1; i <= n; i++) {
        int mn = 0x7f7f7f7f;
        for(int j = 1; j <= i; j++)
            mn = min(mn, d[i - j] + card[j]);
        d[i] = mn;
    }
    cout << d[n];
    
    return 0;
}
