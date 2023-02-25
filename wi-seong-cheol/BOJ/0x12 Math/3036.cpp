//
//  3036.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 8 4 2
 [Output]
 2/1
 4/1
 */
// 시간복잡도: O(nlog(n + m))
// 최악시간: 600
// 난이도: Silver 4
// Timer: 20m
// Url: https://www.acmicpc.net/problem/3036

#include <iostream>

using namespace std;
int n, m;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i < n; i++) {
        int x; cin >> x;
        int mod = gcd(m, x);
        cout << m / mod << '/' << x / mod << '\n';
    }
    
    return 0;
}
