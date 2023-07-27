//
//  6064.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 10 12 3 9
 10 12 7 2
 13 11 5 6
 [Output]
 33
 -1
 83
 */
// 시간복잡도: O(n)
// 최악시간: 40,000
// 난이도: Silver 1
// Timer: 10m
// Url: https://www.acmicpc.net/problem/6064

#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(a == 0) return b;
    return gcd(b%a, a);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int solve(int m, int n, int x, int y) {
    if(x == m) x = 0;
    if(y == n) y = 0;
    int l = lcm(m, n);
    cout << l << '\n';
    for(int i = x; i <= l; i+=m) {
        if(i == 0) continue;
        if(i % n == y)
            return i;
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    while (t--) {
        int m, n, x, y;
        cin >> m >> n >> x >> y;
        cout << solve(m, n, x, y) << '\n';
    }
    
    return 0;
}
