//
//  1670(1).cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/20.
//

/*
 [Input]
 10000
 [Output]
 656444295
 */
// 시간복잡도: O(n ^ 2)
// 최악시간: 100,000,000
// 난이도: Gold 3
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1670

#include <iostream>

using namespace std;
#define ll long long
const ll mod = 987654321;
ll n;
ll d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    d[0] = 1;
    for(int i = 2; i <= n; i += 2) {
        for(int j = 2; j <= i; j += 2) {
            d[i] += (d[j - 2] * d[i - j]);
            d[i] %= mod;
        }
    }
    cout << d[n];
    
    return 0;
}
