//
//  9461.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/02.
//

/*
 [Input]
 2
 6
 12
 [Output]
 3
 16
 */
// 시간복잡도: O(n)
// 최악시간: 100
// 난이도: Silver 3
// Timer: 7m
// Url: https://www.acmicpc.net/problem/9461

#include <iostream>

using namespace std;
#define ll long long
int n;
ll d[101];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int t; cin >> t;
    d[1] = 1; d[2] = 1; d[3] = 1; d[4] = 2; d[5] = 2;
    for(int i = 6; i <= 100; i++)
        d[i] = d[i - 1] + d[i - 5];
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
