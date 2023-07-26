//
//  15989.cpp
//  wi-seong-cheol
//
//  Created by wi_seong on 2023/02/16.
//

/*
 [Input]
 1
 10
 [Output]
 14
 */
// 시간복잡도: O(n)
// 최악시간: 10,000
// 난이도: Silver 1
// Timer: 30m
// Url: https://www.acmicpc.net/problem/15989

#include <iostream>

using namespace std;
#define ll long long
int t, n;
ll d[10001];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    d[1] = 1; d[2] = 2; d[3] = 3;
    for(int i = 4; i < 10001; i++)
        d[i] = d[i - 3] + i / 2 + 1;
    cin >> t;
    while(t--) {
        cin >> n;
        cout << d[n] << '\n';
    }
    
    return 0;
}
