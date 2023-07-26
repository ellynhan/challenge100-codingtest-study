//
//  11727.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 [Output]
 3
 */
// 시간복잡도: O(n)
// 최악시간: 1,000
// 난이도: Silver 3
// Timer: 10m
// Url: https://www.acmicpc.net/problem/11727

#include <iostream>

using namespace std;
int n;
int d[1001];
const int mod = 10007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[1] = 1;
    d[2] = 3;
    for(int i = 3; i <= n; i++) {
        d[i] = (d[i - 1] + 2 * d[i - 2]) % mod;
    }
    cout << d[n];
    
    return 0;
}
