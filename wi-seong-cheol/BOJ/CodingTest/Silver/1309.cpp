//
//  1309.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/15.
//

/*
 [Input]
 100000
 [Output]
 8379
 */
// 시간복잡도: O(n)
// 최악시간: 100,000
// 난이도: Silver 1
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1309

#include <iostream>

using namespace std;
const int mod = 9901;
int n;
int d[100001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 1; d[1] = 3;
    for(int i = 2; i <= n; i++)
        d[i] = (2 * d[i - 1] + d[i - 2]) % mod;
    cout << d[n];
    
    return 0;
}
