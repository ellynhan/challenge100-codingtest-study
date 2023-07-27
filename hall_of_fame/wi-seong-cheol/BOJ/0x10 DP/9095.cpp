//
//  9095.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 3
 4
 7
 10
 [Output]
 7
 44
 274
 */
// 시간복잡도: O(n)
// 최악시간: 10
// 난이도: Silver 3
// Timer: 5m
// Url: https://www.acmicpc.net/problem/9095

#include <iostream>
#include <algorithm>

using namespace std;
int n;
int d[11];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4; i < 11; i++)
        d[i] = d[i - 3] + d[i - 2] + d[i - 1];
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
