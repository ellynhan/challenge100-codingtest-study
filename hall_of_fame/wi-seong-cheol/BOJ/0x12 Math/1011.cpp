//
//  1011.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/28.
//

/*
 [Input]
 3
 0 3
 1 5
 45 50
 [Output]
 3
 3
 4
 */
// 시간복잡도: O(1)
// 최악시간: 1
// 난이도: Gold 5
// Timer: 1h
// Url: https://www.acmicpc.net/problem/1011

#include <iostream>
#include <cmath>

using namespace std;
#define ll long long
int t, x, y;

ll solve(ll k) {
    return floor(2 * sqrt(k) - 1e-9);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;
    while(t--) {
        cin >> x >> y;
        cout << solve(y - x) << '\n';
    }
    
    return 0;
}
