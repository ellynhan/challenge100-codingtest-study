//
//  1904.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 4
 [Output]
 5
 */
// 시간복잡도: O(n)
// 최악시간: 1,000,000
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1904

#include <iostream>

using namespace std;
const int mod = 15746;
int n;
int d[1000001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1] = 1; d[2] = 2;
    for(int i = 3; i <= n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % mod;
    cout << d[n];
    
    return 0;
}
