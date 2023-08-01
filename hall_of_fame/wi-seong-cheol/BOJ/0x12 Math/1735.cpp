//
//  1735.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 2 7
 3 5
 [Output]
 31 35
 */
// 시간복잡도: O(logn)
// 최악시간: 5
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1735

#include <iostream>
#include <numeric>

using namespace std;
int a1, b1, a2, b2;
int n, m;
int _lcm, _gcd;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a1 >> b1 >> a2 >> b2;
    _lcm = lcm(b1, b2);
    n = a1 * (_lcm / b1) + a2 * (_lcm / b2);
    m = _lcm;
    _gcd = gcd(n, m);
    cout << n / _gcd << ' ' << m / _gcd;
    
    return 0;
}
