//
//  4779.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/04/10.
//

/*
 [Input]
 0
 1
 3
 2
 [Output]
 -
 - -
 - -   - -         - -   - -
 - -   - -
 */
// 시간복잡도: O(3 ^ n)
// 최악시간: 531,441
// 난이도: Silver 3
// Timer: 15m
// Url: https://www.acmicpc.net/problem/4779

#include <iostream>
#include <cmath>

using namespace std;
int n;

void solve(int len) {
    if(len == 1) {
        cout << '-';
        return;
    }
    
    solve(len / 3);
    for(int i = 0; i < len / 3; i++)
        cout << ' ';
    solve(len / 3);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while(cin >> n) {
        solve(pow(3, n));
        cout << '\n';
    }
    
    return 0;
}
