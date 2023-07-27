//
//  5347.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 15 21
 33 22
 9 10
 [Output]
 105
 66
 90
 */
// 시간복잡도: O(logn)
// 최악시간: 7
// 난이도: Silver 5
// Timer: 10m
// Url: https://www.acmicpc.net/problem/5347

#include <iostream>

using namespace std;
int t, n, m;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * (b / gcd(a, b));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << lcm(n, m) << '\n';
    }
    
    return 0;
}
