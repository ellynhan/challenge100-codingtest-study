//
//  1003.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 0
 1
 3
 [Output]
 1 0
 0 1
 1 2
 */
// 시간복잡도: O(n)
// 최악시간: 40
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/1003

#include <iostream>

using namespace std;
int n;
int d[41][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    d[0][0] = 1;
    d[1][1] = 1;
    for(int i = 2; i <= 40; i++) {
        d[i][0] = d[i - 1][0] + d[i - 2][0];
        d[i][1] = d[i - 1][1] + d[i - 2][1];
    }
    while(t--) {
        cin >> n;
        cout << d[n][0] << ' ' << d[n][1] << '\n';
    }
    return 0;
}
